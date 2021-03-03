/*
从D-Bus XML自动生成Proxy类#
Proxy Object提供了一种更加直观的方式来访问Service，如同调用本地对象的方法一样。
生成Proxy类的流程如下：

使用工具qdbuscpp2xml从object.h生成XML文件；#
qdbuscpp2xml -M test.h -o com.scorpio.test.xml

使用工具qdbusxml2cpp从XML文件生成继承自QDBusInterface的类#
qdbusxml2cpp com.scorpio.test.xml -p valueInterface
生成两个文件：valueInterface.cpp和valueInterface.h

*/
#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>
#include "test.h"
#include "valueInterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 初始化自动生成的Proxy类com::scorpio::test::value
    com::scorpio::test::value test("com.scorpio.test",
                                   "/test/objects",
                                   QDBusConnection::sessionBus());
    // 调用value方法
    QDBusPendingReply<int> reply = test.value();
    //qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
    //所以需要调用waitForFinished来等到Message执行完成
    reply.waitForFinished();
    if (reply.isValid())
    {
        int value = reply.value();
        qDebug() << QString("value =  %1").arg(value);
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    reply = test.maxValue();

    reply.waitForFinished();
    if (reply.isValid())
    {
        int value = reply.value();
        qDebug() << QString("value =  %1").arg(value);
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}
