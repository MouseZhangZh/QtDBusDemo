#ifndef SERVICE_H
#define SERVICE_H
#include <QtCore/QObject>
#include <QTextStream>
#include <QCoreApplication>
#include <QtDBus>
#include <QDebug>
#include <thread>
class Service: public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "a.b.c.d")
public:
    Service();
public slots:
    void service_get(QString st);
signals:
    void send_to_client(void);
};

#endif // SERVICE_H
