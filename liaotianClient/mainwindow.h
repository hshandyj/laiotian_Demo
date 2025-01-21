#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "liaotianwindow.h"
#include "zhucemainwindow.h"
#include "resetwindow.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



private slots:
    void on_btnArticle_clicked(bool checked);

    void on_btnSignIn_clicked();

    void on_btnClose_clicked();

    void on_btnSignUp_clicked();

    void on_editUser_selectionChanged();

    void on_editPassword_selectionChanged();

    void slotSwitchLogin();

    void slotSwitchReset();

    void on_btnMore_clicked();

    void slot_login_mod_finish(ReqId id,QString res,ErrorCodes err);


signals:
    void sig_connect_tcp(ServerInfo si);


private:
    Ui::MainWindow *ui;
    //拖动窗口
    QPoint mOffset;
    //存储聊天窗口的指针
    LiaotianWindow* liaotianPage;
    //存储注册界面指针
    zhuceMainWindow* zhucePage;
    //重置密码界面
    ResetWindow* resetPage;

    QTimer* _timer;

    int _uid;
    QString _token;

    QMap<TipErr, QString> _tip_errs;

    QMap<ReqId,std::function<void(const QJsonObject&)> > _handlers;

    void showTip(QString str, bool ok);
    bool checkUserValid();
    bool checkPassValid();
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    void initHandlers();
};
#endif // MAINWINDOW_H
