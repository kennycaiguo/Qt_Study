#include "Udp2.h"
#include <QDebug>
#include <QTime>
#include <QTimer>

Udp2::Udp2(QWidget *parent) : QWidget(parent)
{
    udpSocket = new QUdpSocket;
    //udpSocket->bind(10002);

    //加入多播
    udpSocket->bind(QHostAddress::AnyIPv4, 10002);
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.131")); //加入多播

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));

    QTimer* timer = new QTimer;
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
    timer->start();
}

void Udp2::slotReadyRead()
{
    while(udpSocket->hasPendingDatagrams())
    {
        quint32 datagramSize = udpSocket->pendingDatagramSize();
        QByteArray buf(datagramSize, 0);
        udpSocket->readDatagram(buf.data(), buf.size());
        qDebug() << "UDP2" << buf;
    }
}

void Udp2::slotTimeOut()
{
    udpSocket->writeDatagram(QDateTime::currentDateTime().toString().toUtf8(),
                             QHostAddress("127.0.0.1"), 10001);
}

