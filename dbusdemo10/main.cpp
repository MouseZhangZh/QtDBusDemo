/*
使用Adapter注册Object#
可以直接把test类注册为消息总线上的一个Object，但QT4不推荐。QT4推荐使用Adapter来注册Object。
大多数情况下，可能只需要把自定义的类里的方法有选择的发布到消息总线上，使用Adapter可以很方便的实现选择性发布。
生成Adapter类的流程如下：

使用工具 qdbuscpp2xml从test.h生成XML文件
qdbuscpp2xml -M test.h -o com.scorpio.test.xml
编辑com.scorpio.test.xml，选择需要发布的method，不需要发布的删除。
使用工具qdbusxml2cpp从XML文件生成继承自QDBusInterface的类
qdbusxml2cpp com.scorpio.test.xml -i test.h -a valueAdaptor
生成两个文件：valueAdaptor.cpp和valueAdaptor.h
*/
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusError>
#include "test.h"
#include "valueAdaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDBusConnection connection = QDBusConnection::sessionBus();
    test object(60);
    //ValueAdaptor是qdbusxml2cpp生成的Adaptor类
    ValueAdaptor valueAdaptor(&object);
    if (!connection.registerService("com.scorpio.test"))
    {
        qDebug() << connection.lastError().message();
        exit(1);
    }
    connection.registerObject("/test/objects", &object);
    return a.exec();
}
