#ifndef ZHUCEMAINWINDOW_H
#define ZHUCEMAINWINDOW_H

#include "httpmgr.h"
#include "clickedlabel.h"
namespace Ui {
class zhuceMainWindow;
}

class zhuceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    explicit zhuceMainWindow(QWidget *parent = nullptr);
    ~zhuceMainWindow();




private slots:
    void slot_reg_mod_finish(ReqId id,QString res,ErrorCodes err);

    void on_btnExit_clicked();

    void on_btnSignup_clicked();

    void on_editUsername_selectionChanged();

    void on_editEmail_selectionChanged();

    void on_editPassword_selectionChanged();

    void on_editPasswordYes_selectionChanged();

    void on_editCode_selectionChanged();

    void on_btnGetCode_clicked();

private:
    void showTip(QString str,bool ok);

    void initHttpHandlers();
    QMap<ReqId,std::function<void(const QJsonObject&)> > _handlers;

    Ui::zhuceMainWindow *ui;
    //拖动窗口
    QPoint mOffset;

    QMap<TipErr, QString> _tip_errs;

    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    bool checkUserValid();
    bool checkPassValid();
    bool checkEmailValid();
    bool checkVarifyValid();
    bool checkConfirmValid();

signals:
    void sigSwitchLogin();
};

#endif // ZHUCEMAINWINDOW_H
