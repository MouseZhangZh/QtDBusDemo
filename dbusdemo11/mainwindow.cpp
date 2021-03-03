#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDBusConnection::sessionBus().connect("x.y.z",
                                          "/",
                                          "a.b.c.d",
                                          "sayHello",
                                          this,
                                          SLOT(sayHelloSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayHelloSlot()
{
    qDebug("hello");
}

