HEADERS += \
    MyWidget.h \
    TcpClient.h \
    TcpServer.h \
    ChooseInterface.h \
    Udp1.h \
    Udp2.h

SOURCES += \
    MyWidget.cpp \
    TcpClient.cpp \
    TcpServer.cpp \
    ChooseInterface.cpp \
    Udp1.cpp \
    Udp2.cpp

QT += gui widgets network

#使用lambda表达式需要
CONFIG += C++11
