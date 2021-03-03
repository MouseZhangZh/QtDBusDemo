#ifndef DEMO_H
#define DEMO_H

// 必要的头文件
#include <QDBusMessage>
#include <QDBusInterface>
#include <QDBusReply>
#include <QCoreApplication>
#include <QObject>
#include <QDebug>

class DBusDemo: public QObject
{
    Q_OBJECT
    // 定义D-Bus服务名称
    Q_CLASSINFO("D-Bus Interface", "a.b.c.d")
    // 申明属性
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname MEMBER myNickname)

public:
    explicit DBusDemo(QObject *parent = nullptr): QObject(parent) {}
    // 属性-读
    QString nickname() { return myNickname; }
    // 属性-写
    void setNickname(QString name){ myNickname = name; }

public slots:
    // D-Bus方法
    QDBusVariant helloJerry(const QString &name) { return QDBusVariant("Hello " + name); }
    QDBusVariant helloTom() {
        emit sayHelloHelper();
        return QDBusVariant("Hello Tom"); }

signals:
    // D-Bus信号
    void sayHello();

    void sayHelloHelper();

private:
    QString myNickname = "Jerry";
};

#endif // DEMO_H
