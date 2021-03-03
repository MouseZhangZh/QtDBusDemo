/*
 * 这个demo主要演示注册一个session bus
 *
 * 在没有.service文件时需要手动运行这个代码，添加.service之后可以自启
*/
#include "demo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DBusDemo dbusDemo;
    QDBusConnection dbus = QDBusConnection::sessionBus();
    // 尝试注册D-Bus服务，如果注册成功，表示应用没有启动，启动应用。
    // 如果注册失败，则说明应用已经启动了，调用接口，让已启动的应用去完成任务。
    //ps.可以用来实现单例

    if (dbus.registerService("x.y.z")) {
        dbus.registerObject("/l/m/n",
                            &dbusDemo,
                            QDBusConnection::ExportAllSlots
                            | QDBusConnection::ExportAllProperties
                            | QDBusConnection::ExportAllSignals);
        // TODO 启动APP等逻辑
        printf("y\n");
        qDebug("y");

        QObject::connect(&dbusDemo, &DBusDemo::sayHelloHelper, &dbusDemo, [&](){
            //不能用emit直接发送信号
            QDBusMessage message = QDBusMessage::createSignal("/l/m/n", "a.b.c.d", "sayHello");
            dbus.send(message);
            qDebug("have sent");
        });

    } else {
        // TODO 通过上述D-Bus方法调用本服务的接口完成业务逻辑

        printf("n\n");
        qDebug("n");
    }

    return a.exec();
}
/*
自动启动Service
D-Bus系统提供了一种机制可以在访问某个service时，自动把应用程序运行起来。
需要在/usr/share/dbus-1/services下面建立x.y.z.service文件，文件的内容如下：

[D-BUS Service]
Name=x.y.z
Exec=/your/path/to/exec
*/
