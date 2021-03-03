#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 定义D-Bus的接口
    QDBusInterface* interface = new QDBusInterface("x.y.z",
                                                  "/l/m/n",
                                                  "a.b.c.d",
                                                  QDBusConnection::sessionBus());

    // 调用D-Bus接口的方法
    QDBusPendingCall pcall = interface->asyncCall("helloTom");

    // 设置等待异步消息的信号槽
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pcall, nullptr);
    QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, &MainWindow::slotDBusCallFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 处理异步D-Bus消息返回值的槽函数
void MainWindow::slotDBusCallFinished(QDBusPendingCallWatcher *wather)
{
    // 根据消息返回值类型定义QDBusPendingReply
    QDBusPendingReply<QDBusVariant> reply = *wather;
    QString isVisable = reply.argumentAt<0>().variant().toString();
    wather->deleteLater();
    qInfo() << isVisable;
}

