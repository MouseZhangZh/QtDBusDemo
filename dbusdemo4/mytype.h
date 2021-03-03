#ifndef MYTYPE_H
#define MYTYPE_H

// 必要的头文件
#include <QDBusMessage>
#include <QDBusInterface>
#include <QDBusReply>
#include <QCoreApplication>
#include <QDebug>
#include <QtDBus>

class MyType
{
public:
    MyType() = default;
    MyType(QString&, int&);
    friend QDBusArgument& operator<<(QDBusArgument &argument, const MyType &message);
    friend const QDBusArgument& operator>>(const QDBusArgument &argument, MyType &message);
    static void registerMetaType();
    void showInfo() { qDebug() << this->s_name << " " << this->i_age; }
private:
    QString s_name = "MouseZhangZh";
    int i_age = 21;
};

Q_DECLARE_METATYPE(MyType)


#endif // MYTYPE_H
