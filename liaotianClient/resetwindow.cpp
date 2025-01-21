#include "resetwindow.h"
#include "ui_resetwindow.h"

#include <QDebug>
#include <QRegularExpression>
ResetWindow::ResetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ResetWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景

    ui->label->SetState("unvisible","unvisible_hover","","visible",
                               "visible_hover","");

    connect(ui->label, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->label->GetCurState();
        if(state == ClickLbState::Normal){
            ui->editPassword->setEchoMode(QLineEdit::Password);
        }else{
            ui->editPassword->setEchoMode(QLineEdit::Normal);
        }
        //qDebug() << "Label was clicked!";
    });


    connect(ui->editUsername,&QLineEdit::editingFinished,this,[this](){
        checkUserValid();
    });

    connect(ui->editEmail, &QLineEdit::editingFinished, this, [this](){
        checkEmailValid();
    });

    connect(ui->editPassword, &QLineEdit::editingFinished, this, [this](){
        checkPassValid();
    });

    connect(ui->editCode, &QLineEdit::editingFinished, this, [this](){
        checkVarifyValid();
    });

    //连接reset相关信号和注册处理回调
    initHandlers();
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reset_mod_finish, this,
            &ResetWindow::slot_reset_mod_finish);


}

ResetWindow::~ResetWindow()
{
    delete ui;
}

void ResetWindow::on_btnBack_clicked()
{
    emit sigSwitchReset();
}

void ResetWindow::slot_reset_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err!=ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        return ;
    }
    //解析json字符串，res转化为QByteArray
    QJsonDocument jsonDoc=QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        showTip(tr("json解析错误"),false);
        return ;
    }
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误"),false);
        return ;
    }

    _handlers[id](jsonDoc.object());
    return ;
}

void ResetWindow::showTip(QString str,bool ok)
{
    if(ok){
        ui->err_tip->setProperty("state","normal");
    }
    else{
        ui->err_tip->setProperty("state","err");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);

}

void ResetWindow::initHandlers()
{
    //注册获取验证码
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){
        int error=jsonObj["error"].toInt();
        if(error!=ErrorCodes::SUCCESS){
            showTip(tr("获取验证码失败"),false);
            return ;
        }
        //auto email=jsonObj["email"].toString();
        showTip(tr("验证码已经发送到邮箱，请注意查收"),true);
        //qDebug()<<"email is"<<email;
    });
    //注册获取验证码
    _handlers.insert(ReqId::ID_RESET_USER,[this](const QJsonObject& jsonObj){
        int error=jsonObj["error"].toInt();
        if(error!=ErrorCodes::SUCCESS){
            showTip(tr("重置密码失败"),false);
            return ;
        }
        showTip(tr("重置密码成功"),true);
    });
}

bool ResetWindow::checkUserValid()
{
    if(ui->editUsername->text() == ""){
        AddTipErr(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_USER_ERR);
    return true;
}


bool ResetWindow::checkPassValid()
{
    auto pass = ui->editPassword->text();

    if(pass.length() < 6 || pass.length()>15){
        //提示长度不准确
        AddTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pass).hasMatch();
    if(!match){
        //提示字符非法
        AddTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
        return false;;
    }

    DelTipErr(TipErr::TIP_PWD_ERR);

    return true;
}

bool ResetWindow::checkEmailValid()
{
    //验证邮箱的地址正则表达式
    auto email = ui->editEmail->text();
    // 邮箱地址的正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
    if(!match){
        //提示邮箱不正确
        AddTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }

    DelTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool ResetWindow::checkVarifyValid()
{
    auto pass = ui->editCode->text();
    if(pass.isEmpty()){
        AddTipErr(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_VARIFY_ERR);
    return true;
}

void ResetWindow::AddTipErr(TipErr te, QString tips)
{
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void ResetWindow::DelTipErr(TipErr te)
{
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
        ui->err_tip->clear();
        return;
    }

    showTip(_tip_errs.first(), false);
}

void ResetWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void ResetWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}

void ResetWindow::on_btnVarify_clicked()
{
    auto email = ui->editEmail->text();
    auto bcheck = checkEmailValid();
    if(!bcheck){
        return;
    }

    //发送http请求获取验证码
    QJsonObject json_obj;
    json_obj["email"] = email;
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),
                                        json_obj, ReqId::ID_GET_VARIFY_CODE,Modules::RESETMOD);
}


void ResetWindow::on_btnSure_clicked()
{
    bool valid = checkUserValid();
    if(!valid){
        return;
    }
    valid = checkEmailValid();
    if(!valid){
        return;
    }
    valid = checkPassValid();
    if(!valid){
        return;
    }
    valid = checkVarifyValid();
    if(!valid){
        return;
    }

    //day11 发送http请求注册用户
    QJsonObject json_obj;
    json_obj["user"] = ui->editUsername->text();
    json_obj["email"] = ui->editEmail->text();
    json_obj["passwd"] = xorString(ui->editPassword->text());
    json_obj["varifycode"] = ui->editCode->text();
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/reset_pwd"),
                                        json_obj, ReqId::ID_RESET_USER,Modules::RESETMOD);
}

