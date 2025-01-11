#include "zhucemainwindow.h"
#include "ui_zhucemainwindow.h"

zhuceMainWindow::zhuceMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zhuceMainWindow)
{
    ui->setupUi(this);
}

zhuceMainWindow::~zhuceMainWindow()
{
    delete ui;
}
