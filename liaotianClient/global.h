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

enum ReqId{
    ID_GET_VARIFY_CODE=1001,//获取验证码
    ID_REG_USER=1002,//注册账户

};

enum Modules{
    REGISTERMOD=0,

};

enum ErrorCodes{
    SUCCESS=0,
    ERR_JSON=1,//json解析失败
    ERR_NETWORK=2,//网络错误
};



//刷新qss
extern std::function<void(QWidget*)> repolish;

#endif // GLOBAL_H
