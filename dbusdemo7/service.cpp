#include "service.h"

Service::Service()
{
//    QDBusConnection::sessionBus().unregisterService("a.b.c.d");
//    QDBusConnection::sessionBus().registerService("a.b.c.d");
//    QDBusConnection::sessionBus().registerObject("/l/m/n", this,QDBusConnection :: ExportAllSlots | QDBusConnection :: ExportAllSignals);
    QDBusConnection::sessionBus().connect(QString(), QString("/l/m/n"), "a.b.c.d", "send_to_service", this, SLOT(service_get(QString)));
}
void Service::service_get(QString st)
{
    qDebug() << "Message get from client: "<< st;
}

