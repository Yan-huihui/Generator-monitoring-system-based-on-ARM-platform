# C/S服务器：
基于TCP/IP协议，将开发板采集到的数据通过设备号分表存储到sqlite3数据库中，使用epoll实现并发。
# B/S服务器：
基于HTTP协议，用户可以通过浏览器访问服务器。登录成功可以通过输入设备号查询历史数据。
