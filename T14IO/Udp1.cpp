#include "Udp1.h"
#include <QDebug>
#include <QTime>
#include <QTimer>

Udp1::Udp1(QWidget *parent) : QWidget(parent)
{
    udpSocket = new QUdpSocket;
    udpSocket->bind(10001);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));

    QTimer* timer = new QTimer;
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
    timer->start();
}

void Udp1::slotReadyRead()
{
    while(udpSocket->hasPendingDatagrams())
    {
        quint32 datagramSize = udpSocket->pendingDatagramSize();
        QByteArray buf(datagramSize, 0);
        udpSocket->readDatagram(buf.data(), buf.size());
        qDebug() << "UDP1" << buf;
    }
}

void Udp1::slotTimeOut()
{
    /*udpSocket->writeDatagram(QDateTime::currentDateTime().toString().toUtf8(),
                             QHostAddress("127.0.0.1"), 10002);*/
    /*udpSocket->writeDatagram(QDateTime::currentDateTime().toString().toUtf8(),
                             QHostAddress::Broadcast, 10002); */ //广播
    udpSocket->writeDatagram(QDateTime::currentDateTime().toString().toUtf8(),
                             QHostAddress("224.0.0.131"), 10002);
}

