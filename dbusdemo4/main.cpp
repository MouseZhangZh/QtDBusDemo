/*
 * 这个demo主要演示扩展类型
*/
#include <QCoreApplication>
#include "demo.h"
#include "MyTypeInterface.h"

/*
D-Bus有一种基于几种原生与在数组和结构中的原生类型组成的复合类型的扩展类型系统。
QtDBus模块通过QDBusArgument类实现了类型系统，允许用户通过总线发送和接收每一种C++类型。
原生类型：
QT类型          D-BUS类型
uchar            BYTE
bool             BOOLEAN
short            INT16
ushort           UINT16
int              INT32
uint             UINT32
qlonglong        INT64
qulonglong       UINT64
double           DOUBLE
QString	         STRING
QDBusVariant     VARIANT
QDBusObjectPath	 OBJECT_PATH
QDBusSignature   SIGNATURE
除了原生类型，QDBusArgument也支持在Qt应用中广泛使用的两种非原生类型，QStringList和QByteArray。
*/

/*
复合类型：
D-Bus指定由原生类型聚合而成的三种复合类型：
ARRAY、STRUCT和 maps/dictionaries。
ARRAY零个或多个相同元素的集合，
STRUCT是由不同类型的固定数量的元素组成的集合，
Maps or dictionaries是元素对的数组，
一个map中可以有零个或多个元素。
*/

/*
扩展类型系统：
为了在QtDBus模块使用自定义类型，自定义类型必须使用Q_DECLARE_METATYPE()声明为Qt元类型，
使用qDBusRegisterMetaType()函数注册。
流操作符会被注册系统自动找到。
QtDBus模块为Qt容器类使用数组和map提供了模板特化，例如QMap和QList，不必实现流操作符函数。
对于其它的类型，流操作符必须显示实现。
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //注意此处的类型注册~
    MyType::registerMetaType();

    a::b::c::d test("x.y.z", "/l/m/n", QDBusConnection::sessionBus());
    QString name = "wow";
    int age = 18;
    // 调用value方法
    QDBusPendingReply<MyType> reply = test.hello(MyType(name, age));
    //qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
    //所以需要调用waitForFinished来等到Message执行完成
    reply.waitForFinished();
    MyType value = reply.value();
    if (reply.isValid())
    {
        MyType value = reply.value();
//        qDebug() << QString("value =  %1").arg(value);
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}
