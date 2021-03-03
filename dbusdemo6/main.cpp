/*
 * 这个demo主要演示使用createSignal传递消息
*/
#include "client.h"

void client_listen()
{
    std::string str;
    while(true)
    {
//        getchar();
        qDebug() << "Message send!";
        QDBusMessage message =QDBusMessage::createSignal("/l/m/n", "a.b.c.d", "send_to_service");
//        message << QString("Hello world!");
        std::cin >> str;
        message << QString().fromStdString(str);
        QDBusConnection::sessionBus().send(message);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    std::thread th1(client_listen);
    th1.detach();

    return a.exec();
}
