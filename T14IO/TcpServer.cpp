#include "TcpServer.h"
#include <QHBoxLayout>
#include <QNetworkInterface>
#include <QMessageBox>
#include "ChooseInterface.h"
TcpServer::TcpServer(QWidget *parent) : QWidget(parent)
{
    // 创建服务器并监听
    server = new QTcpServer;

    ChooseInterface dlg;
    dlg.exec();
    QMessageBox::information(NULL,"you select the ip:", dlg.strSelect);

    //server->listen(QHostAddress::Any, 9988);
    server->listen(QHostAddress(dlg.strSelect), 9988);

    // 当有客户端来连接时，调用slotNetConnection方法
    connect(server, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));

    _show = new QTextBrowser;
    QHBoxLayout* lay = new QHBoxLayout(this);
    lay->addWidget(_show);
}

void TcpServer::slotNewConnection()
{
    // 判断是否有未处理的连接
    while(server->hasPendingConnections())
    {
        // 调用nextPeddingConnection去获得连接的socket
        socket = server->nextPendingConnection();
        // 为新的socket提供槽函数，来接收数据
        connect(socket, SIGNAL(readyRead()),
                this, SLOT(slotReadyRead()));
    }

}

void TcpServer::slotReadyRead()
{
    // 接收数据，判断是否有数据，如果有，通过readAll函数获取所有数据
    while(socket->bytesAvailable() > 0)
    {
        QByteArray buf = socket->readAll();
        _show->append(buf);
    }
}

