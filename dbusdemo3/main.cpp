/*
 * 这个demo主要演示使用QDBusInterface连接session bus
*/
#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 创建QDBusInterface接口
    QDBusInterface interface("x.y.z", "/l/m/n",
                             "a.b.c.d",
                             QDBusConnection::sessionBus());
    if (!interface.isValid())
    {
        qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
        exit(-1);
    }


    /*
    QDBusReply类用于存储对远程对象的方法调用的应答。
    一个QDBusReply对象是方法调用的应答QDBusMessage对象的一个子集。
    QDBusReply对象只包含第一个输出参数或错误代码，并由QDBusInterface派生类使用，以允许将错误代码返回为函数的返回参数。
    对于没有输出参数或返回值的远程调用，使用isValid()函数测试应答是否成功。
    */

    //调用远程的helloTom方法
    QDBusReply<QVariant> reply = interface.call("helloTom");
    qDebug() << reply;
    if (reply.isValid())
    {
        QString value = reply.value().value<QString>();
        qDebug() << value;
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    //调用远程的helloJerry方法
    QDBusReply<QVariant> reply1 = interface.call("helloJerry", "Jerry");
    qDebug() << reply1;
    if (reply1.isValid())
    {
        QString value1 = reply1.value().value<QString>();
        qDebug() << value1;
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}
