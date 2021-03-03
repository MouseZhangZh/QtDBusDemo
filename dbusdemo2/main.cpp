/*
 * 这个demo主要演示使用QDBusMessage设置参数连接session bus
*/
#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusVariant>
#include <QDBusArgument>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    //构造一个method_call消息，为了区分，服务名称为：x.y.z，对象路径为：/l/m/n
    //接口名称为a.b.c.d,method名称为helloJerry
    QDBusMessage message = QDBusMessage::createMethodCall("x.y.z",
                           "/l/m/n",
                           "a.b.c.d",
                           "helloJerry");
    //设置参数List
    message.setArguments(QList<QVariant>() << QVariant("Jerry"));
    //发送消息
    QDBusMessage response = QDBusConnection::sessionBus().call(message);
    //判断method是否被正确返回
    if (response.type() == QDBusMessage::ReplyMessage)
    {
        //从返回参数获取返回值

        QString tmp = response.arguments().at(0).value<QDBusVariant>().variant().toString();

        qDebug() << response;
        qDebug() << response.arguments();
        qDebug() << response.arguments().at(0);
        qDebug() << response.arguments().at(0).value<QDBusVariant>().variant();
        qDebug() << response.arguments().at(0).value<QDBusVariant>().variant().toString();
        qDebug() << tmp;
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}
