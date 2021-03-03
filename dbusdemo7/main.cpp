/*
 * 这个demo主要演示使用createSignal传递消息
*/
#include "service.h"

void service_listen()
{
    while(true)
    {
        getchar();
        qDebug() << "Message send!";
        QDBusMessage message =QDBusMessage::createSignal("/l/m/n", "a.b.c.d", "send_to_client");
        QDBusConnection::sessionBus().send(message);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Service service;

    new Service();

    std::thread th1(service_listen);

    th1.detach();

    return a.exec();
}

