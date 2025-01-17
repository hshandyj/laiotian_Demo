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
    showTip("格式正确",true);
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finish,
            this,&zhuceMainWindow::slot_reg_mod_finish);
    initHttpHandlers();

}

zhuceMainWindow::~zhuceMainWindow()
{
    delete ui;
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
        showTip(tr("用户注册成功"), true);
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
    QApplication::quit();
}


void zhuceMainWindow::on_btnSignup_clicked()
{
    if(ui->editUsername->text() == ""){
        showTip(tr("用户名不能为空"), false);
        return;
    }

    if(ui->editEmail->text() == ""){
        showTip(tr("邮箱不能为空"), false);
        return;
    }

    if(ui->editPassword->text() == ""){
        showTip(tr("密码不能为空"), false);
        return;
    }

    if(ui->editPasswordYes->text() == ""){
        showTip(tr("确认密码不能为空"), false);
        return;
    }

    if(ui->editPassword->text() != ui->editPasswordYes->text()){
        showTip(tr("密码和确认密码不匹配"), false);
        return;
    }

    if(ui->editCode->text() == ""){
        showTip(tr("验证码不能为空"), false);
        return;
    }

    //day11 发送http请求注册用户
    QJsonObject json_obj;
    json_obj["user"] = ui->editUsername->text();
    json_obj["email"] = ui->editEmail->text();
    json_obj["passwd"] = ui->editPassword->text();
    json_obj["confirm"] = ui->editPasswordYes->text();
    json_obj["varifycode"] = ui->editCode->text();
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/user_register"),
                                        json_obj, ReqId::ID_REG_USER,Modules::REGISTERMOD);

    // this->hide();
    // this->liaotianPage->show();
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
        ui->editPassword->setEchoMode(QLineEdit::Password);
    }
}


void zhuceMainWindow::on_editPasswordYes_selectionChanged()
{
    if(ui->editPasswordYes->text()=="确认密码"){
        ui->editPasswordYes->clear();
        ui->editPasswordYes->setEchoMode(QLineEdit::Password);
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

