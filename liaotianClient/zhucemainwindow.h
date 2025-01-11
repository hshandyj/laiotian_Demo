#ifndef ZHUCEMAINWINDOW_H
#define ZHUCEMAINWINDOW_H

#include <QMouseEvent>
#include <QMainWindow>

#include "liaotianwindow.h"

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
    void on_btnExit_clicked();

    void on_btnSignup_clicked();

    void on_editUsername_selectionChanged();

    void on_editEmail_selectionChanged();

    void on_editPassword_selectionChanged();

    void on_editPasswordYes_selectionChanged();

    void on_editCode_selectionChanged();

private:
    Ui::zhuceMainWindow *ui;
    //拖动窗口
    QPoint mOffset;
    //存储聊天窗口的指针
    LiaotianWindow* liaotianPage;
};

#endif // ZHUCEMAINWINDOW_H
