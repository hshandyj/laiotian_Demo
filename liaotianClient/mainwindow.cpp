#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景
    liaotianPage=new LiaotianWindow(this);
    zhucePage=new zhuceMainWindow(this);
    resetPage=new ResetWindow(this);
    _timer=new QTimer(this);
    connect(zhucePage,&zhuceMainWindow::sigSwitchLogin,this,&MainWindow::slotSwitchLogin);
    connect(resetPage,&ResetWindow::sigSwitchReset,this,&MainWindow::slotSwitchReset);
    connect(ui->editUser,&QLineEdit::editingFinished,this,[this](){
        checkUserValid();
    });

    connect(ui->editPassword, &QLineEdit::editingFinished, this, [this](){
        checkPassValid();
    });
    initHandlers();
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reset_mod_finish, this,
            &MainWindow::slot_login_mod_finish);
    connect(_timer,&QTimer::timeout,this,[this](){
        _timer->stop();
        this->hide();
        liaotianPage->show();
    });
}

MainWindow::~MainWindow()
{
    //qDebug()<<"MainWindow";
    delete ui;
}

void MainWindow::showTip(QString str,bool ok)
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

void MainWindow::AddTipErr(TipErr te, QString tips)
{
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void MainWindow::DelTipErr(TipErr te)
{
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
        ui->err_tip->clear();
        return;
    }

    showTip(_tip_errs.first(), false);
}

void MainWindow::initHandlers()
{
    //注册获取登录回包逻辑
    _handlers.insert(ReqId::ID_LOGIN_USER, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("登录失败"),false);
            return;
        }
        //auto user = jsonObj["user"].toString();
        showTip(tr("登录成功"), true);
        ServerInfo si;
        si.Host=jsonObj["host"].toString();
        si.Port=jsonObj["port"].toString();
        si.Token=jsonObj["token"].toString();
        si.Uid=jsonObj["uid"].toInt();
        _uid=si.Uid;
        _token=si.Token;
        _timer->start(1000);
        emit sig_connect_tcp(si);
        //qDebug()<< "user is " << user ;
    });
}

bool MainWindow::checkUserValid()
{
    if(ui->editUser->text() == ""){
        AddTipErr(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_USER_ERR);
    return true;
}

bool MainWindow::checkPassValid()
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}

void MainWindow::on_btnArticle_clicked(bool checked)
{
    if(checked){
        ui->btnSignIn->setStyleSheet("border:none;background-color: rgb(55, 142, 255);border-radius:10px;color: rgb(255, 255, 255);");
        ui->btnSignIn->setEnabled(true);
    }
    else{
        ui->btnSignIn->setStyleSheet("border:none;background-color: rgb(170, 214, 255);border-radius:10px;color: rgb(255, 255, 255);");
        ui->btnSignIn->setEnabled(false);
    }
}

void MainWindow::on_btnSignIn_clicked()
{
    bool valid = checkUserValid();
    if(!valid){
        return;
    }
    valid = checkPassValid();
    if(!valid){
        return;
    }
    QJsonObject json_obj;
    json_obj["user"] = ui->editUser->text();
    json_obj["passwd"] = xorString(ui->editPassword->text());
    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/user_login"),
                                        json_obj, ReqId::ID_LOGIN_USER,Modules::LOGINMOD);
}

void MainWindow::on_btnClose_clicked()
{
    QApplication::quit();
}

void MainWindow::on_btnSignUp_clicked()
{
    this->hide();
    zhucePage->show();
}

void MainWindow::on_editUser_selectionChanged()
{
    if(ui->editUser->text()=="输入QQ号")
        ui->editUser->clear();
}

void MainWindow::on_editPassword_selectionChanged()
{
    if(ui->editPassword->text()=="输入QQ密码")
    {
        ui->editPassword->clear();
        ui->editPassword->setEchoMode(QLineEdit::Password);
    }

}

void MainWindow::slotSwitchLogin()
{
    zhucePage->hide();
    this->show();
}

void MainWindow::slotSwitchReset()
{
    resetPage->hide();
    this->show();
}


void MainWindow::on_btnMore_clicked()
{
    this->hide();
    resetPage->show();
}

void MainWindow::slot_login_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        showTip(tr("json解析错误"),false);
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误"),false);
        return;
    }


    //调用对应的逻辑,根据id回调。
    _handlers[id](jsonDoc.object());

    return;
}


