#ifndef ZHUCEMAINWINDOW_H
#define ZHUCEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class zhuceMainWindow;
}

class zhuceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit zhuceMainWindow(QWidget *parent = nullptr);
    ~zhuceMainWindow();

private:
    Ui::zhuceMainWindow *ui;
};

#endif // ZHUCEMAINWINDOW_H
