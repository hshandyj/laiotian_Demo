#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QContextMenuEvent>
#include <QMouseEvent>
#include <QMainWindow>

#include "liaotianwindow.h"

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

private:
    Ui::MainWindow *ui;
    //拖动窗口
    QPoint mOffset;
    //存储第二个窗口的指针
    LiaotianWindow* liaotianPage;
};
#endif // MAINWINDOW_H
