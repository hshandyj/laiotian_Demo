#include "zhucemainwindow.h"
#include "ui_zhucemainwindow.h"
zhuceMainWindow::zhuceMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zhuceMainWindow)
{
    liaotianPage=new LiaotianWindow();
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finish,
            this,&zhuceMainWindow::slot_reg_mod_finish);
    initHttpHandlers();

    connect(ui->editUsername,&QLineEdit::editingFinished,this,[this](){
        checkUserValid();
    });

    connect(ui->editEmail, &QLineEdit::editingFinished, this, [this](){
        checkEmailValid();
    });

    connect(ui->editPassword, &QLineEdit::editingFinished, this, [this](){
        checkPassValid();
    });

    connect(ui->editPasswordYes, &QLineEdit::editingFinished, this, [this](){
        checkConfirmValid();
    });

    connect(ui->editCode, &QLineEdit::editingFinished, this, [this](){
        checkVarifyValid();
    });

    ui->pass_visible->setCursor(Qt::PointingHandCursor);
    ui->confirm_visible->setCursor(Qt::PointingHandCursor);
    ui->pass_visible->SetState("unvisible","unvisible_hover","","visible",
                               "visible_hover","");

    ui->confirm_visible->SetState("unvisible","unvisible_hover","","visible",
                                  "visible_hover","");
    //连接点击事件

    connect(ui->pass_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->pass_visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->editPassword->setEchoMode(QLineEdit::Password);
        }else{
            ui->editPassword->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });

    connect(ui->confirm_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->confirm_visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->editPasswordYes->setEchoMode(QLineEdit::Password);
        }else{
            ui->editPasswordYes->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });

}

zhuceMainWindow::~zhuceMainWindow()
{
    //qDebug()<<"zhuceMainWindow";
    delete ui;
}

void zhuceMainWindow::AddTipErr(TipErr te, QString tips)
{
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void zhuceMainWindow::DelTipErr(TipErr te)
{
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
        ui->errTip->clear();
        return;
    }

    showTip(_tip_errs.first(), false);
}


bool zhuceMainWindow::checkUserValid()
{
    if(ui->editUsername->text() == ""){
        AddTipErr(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_USER_ERR);
    return true;
}


bool zhuceMainWindow::checkPassValid()
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

bool zhuceMainWindow::checkConfirmValid()
{
    auto pass = ui->editPassword->text();
    auto confirm=ui->editPasswordYes->text();
    if(pass!=confirm){
        AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("密码和确认密码不一致"));
        return false;
    }
    DelTipErr(TipErr::TIP_CONFIRM_ERR);
    return true;
}

bool zhuceMainWindow::checkEmailValid()
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

bool zhuceMainWindow::checkVarifyValid()
{
    auto pass = ui->editCode->text();
    if(pass.isEmpty()){
        AddTipErr(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_VARIFY_ERR);
    return true;
}



void zhuceMainWindow::showTip(QString str,bool ok)
{
    if(ok){
        ui->errTip->setProperty("state","normal");
    }
    else{
        ui->errTip->setProperty("state","err");
    }
    ui->errTip->setText(str);
    repolish(ui->errTip);

}

void zhuceMainWindow::initHttpHandlers()
{
    //注册获取验证码
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){
        int error=jsonObj["error"].toInt();
        if(error!=ErrorCodes::SUCCESS){
            showTip(tr("获取验证码失败"),false);
            return ;
        }
        auto email=jsonObj["email"].toString();
        showTip(tr("验证码已经发送到邮箱，请注意查收"),true);
        qDebug()<<"email is"<<email;
    });

    _handlers.insert(ReqId::ID_REG_USER, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("注册失败"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        this->hide();
        this->liaotianPage->show();
        showTip(tr("用户注册成功"), true);
        qDebug()<< "user uuid is " << jsonObj["uudi"].toString() ;
        qDebug()<< "email is " << email ;
    });
}

void zhuceMainWindow::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
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

void zhuceMainWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void zhuceMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}



void zhuceMainWindow::on_btnExit_clicked()
{
    emit sigSwitchLogin();
    //QApplication::quit();
}


void zhuceMainWindow::on_btnSignup_clicked()
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
    valid=checkConfirmValid();
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
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/user_register"),
                                        json_obj, ReqId::ID_REG_USER,Modules::REGISTERMOD);

}


void zhuceMainWindow::on_editUsername_selectionChanged()
{
    if(ui->editUsername->text()=="输入用户名"){
        ui->editUsername->clear();
    }
}


void zhuceMainWindow::on_editEmail_selectionChanged()
{
    if(ui->editEmail->text()=="输入邮箱"){
        ui->editEmail->clear();
    }
}


void zhuceMainWindow::on_editPassword_selectionChanged()
{
    if(ui->editPassword->text()=="输入密码"){
        ui->editPassword->clear();
    }
}


void zhuceMainWindow::on_editPasswordYes_selectionChanged()
{
    if(ui->editPasswordYes->text()=="确认密码"){
        ui->editPasswordYes->clear();
    }
}


void zhuceMainWindow::on_editCode_selectionChanged()
{
    if(ui->editCode->text()=="验证码"){
        ui->editCode->clear();
    }
}


void zhuceMainWindow::on_btnGetCode_clicked()
{
    auto email=ui->editEmail->text();
    QRegularExpression regex(R"((\w+)(.|_)?(\w+)@(\w+)(\.(\w+))+)");
    bool match=regex.match(email).hasMatch();
    if(match){
        //http验证码
        QJsonObject json_obj;
        json_obj["email"]=email;
        HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),
                                            json_obj, ReqId::ID_GET_VARIFY_CODE,Modules::REGISTERMOD);

    }
    else{
        showTip(tr("邮箱地址不正确"),false);
    }
}

