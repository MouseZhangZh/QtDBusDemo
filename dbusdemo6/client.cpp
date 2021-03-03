#include "client.h"

Client::Client()
{
    QDBusConnection::sessionBus().connect(QString(), QString("/l/m/n"), "a.b.c.d", "send_to_client", this, SLOT(client_get(void)));
}

void Client::client_get()
{
    qDebug() << "Client get!";
}
