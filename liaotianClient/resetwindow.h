#ifndef RESETWINDOW_H
#define RESETWINDOW_H

#include <QMainWindow>
#include "httpmgr.h"
namespace Ui {
class ResetWindow;
}

class ResetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResetWindow(QWidget *parent = nullptr);
    ~ResetWindow();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



private slots:
    void on_btnBack_clicked();
    void slot_reset_mod_finish(ReqId id,QString res,ErrorCodes err);

    void on_btnVarify_clicked();

    void on_btnSure_clicked();

signals:
    void sigSwitchReset();


private:
    Ui::ResetWindow *ui;
    QMap<TipErr, QString> _tip_errs;

    QMap<ReqId,std::function<void(const QJsonObject&)> > _handlers;
    //拖动窗口
    QPoint mOffset;

    bool checkUserValid();
    bool checkEmailValid();
    bool checkPassValid();
    bool checkVarifyValid();
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    void showTip(QString str, bool ok);
    void initHandlers();
};

#endif // RESETWINDOW_H
