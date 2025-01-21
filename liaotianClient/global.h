#ifndef GLOBAL_H
#define GLOBAL_H
#include<QMouseEvent>
#include<QMainWindow>
#include<QDebug>
#include<QWidget>
#include<functional>
#include<QStyle>
#include<QRegularExpression>
#include<memory>
#include<mutex>
#include<iostream>
#include<QByteArray>
#include<QNetworkReply>
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDir>
#include <QSettings>
enum ReqId{
    ID_GET_VARIFY_CODE=1001,//获取验证码
    ID_REG_USER=1002,//注册账户
    ID_RESET_USER=1003,
    ID_LOGIN_USER=1004,
};

enum Modules{
    REGISTERMOD=0,
    RESETMOD=1,
    LOGINMOD=2,
};

enum ErrorCodes{
    SUCCESS=0,
    ERR_JSON=1,//json解析失败
    ERR_NETWORK=2,//网络错误
};

enum TipErr{
    TIP_SUCCESS = 0,
    TIP_EMAIL_ERR = 1,
    TIP_PWD_ERR = 2,
    TIP_CONFIRM_ERR = 3,
    TIP_PWD_CONFIRM = 4,
    TIP_VARIFY_ERR = 5,
    TIP_USER_ERR = 6
};

enum ClickLbState{
    Normal = 0,
    Selected = 1
};

struct ServerInfo{
    QString Host;
    QString Port;
    QString Token;
    int Uid;
};

//刷新qss
extern std::function<void(QWidget*)> repolish;

extern std::function<QString(QString)> xorString;

extern QString gate_url_prefix;

#endif // GLOBAL_H
