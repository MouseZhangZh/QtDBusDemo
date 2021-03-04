# 简介

对QtDBus的一个小总结，难免有错误或不足之处，欢迎issue和pull request ! >_<

参考资料在我的[blog](https://mousezhangzh.github.io)(有待补充，其实看完参考资料里的东西就够用了，深入理解dbus仍需翻阅源码等)，同样欢迎issue和pull request.

# 目录介绍(标号即为Demo序号)

0. 如何创建session bus

1. 以QDBusMessage(无参)方式调用Demo0的session bus，调用之前需要运行Demo0，或者在/usr/share/dbus-1/services创建Demo0的service文件

2. 以QDBusMessage(有参)方式调用Demo0的session bus

3. 以QDBusInterface(有参和无参方式)调用Demo0的session bus

4. 传对象(未完成)

5. 传对象(未完成)

6. 使用QDBusMessage::createSignal(有参)传递消息，与Demo7互为客户-服务端

7. 使用QDBusMessage::createSignal(无参)传递消息，与Demo6互为客户-服务端

8. 异步调用Demo0的session bus

9. 使用工具生成Proxy类，是Demo10的客户端

10. 使用工具生成Adaptor类，是Demo9的服务端

11. 以connect方式接受Demo0的信号，在Demo6和7中已有所体现

12. 如何创建system bus，有时间把霞姐的[Demo](https://github.com/wx-kylin/system_bus_demo)偷过来，完善一下

13. to be continue


# 问题（待完成，有问题可以直接issue）

1. 各种创建方法的使用场景 

2. system bus 与 session bus 对比

3. 具体原理

4. 安全性

5. system bus 应用场景

6. 如何创建一个system bus 

7. 没有服务名，只有接口和方法，如何使用

8. dbus传递对象和结构体等（虽说大部分都不需要这样做，个人并不认为就不需要弄明白如何传递他们了）

# 自我批评

1. 调整心态

2. 条理不够清晰

3. 没有把握好广度与深度的平衡

4. 虽想不用PPT，但列出一堆代码会让人感到迷惑，没有把握好方式

# 经验总结

1. 以后使用PPT、Markdown和Demo并进的组合，PPT可用于讲解，列出差异、核心步骤等，简单明了，只需把握大体，具体细节写在Markdown里，与代码相照应，代码中的注释也与Markdown里相吻合。

2. 把握好广度与深度，过广会导致听众无法一下子接受那么多内容，过深会导致晦涩难懂（或许），应多多请教其他人，咨询意见，做好功课。

3. 调整心态，心性的磨炼不可停歇。
