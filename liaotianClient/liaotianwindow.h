#ifndef LIAOTIANWINDOW_H
#define LIAOTIANWINDOW_H

#include "httpmgr.h"
namespace Ui {
class LiaotianWindow;
}

class LiaotianWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiaotianWindow(QWidget *parent = nullptr);
    ~LiaotianWindow();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


public:


private slots:
    void on_btnClose_clicked();

    void on_btnSend_clicked();

private:
    Ui::LiaotianWindow *ui;
    //拖动窗口
    QPoint mOffset;

};

#endif // LIAOTIANWINDOW_H
