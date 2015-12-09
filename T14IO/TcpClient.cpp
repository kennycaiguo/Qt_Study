#include "TcpClient.h"

#include <QHboxLayout>
#include <QPushButton>

TcpClient::TcpClient(QWidget *parent) : QWidget(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 9988);

    lineEdit = new QLineEdit;
    QPushButton* button = new QPushButton("Send");

    QHBoxLayout* lay = new QHBoxLayout(this);
    lay->addWidget(lineEdit);
    lay->addWidget(button);

    connect(button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClick()));

    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(slotButtonClick()));
}

void TcpClient::slotButtonClick()
{
    QString strText = lineEdit->text();
    if(strText.isEmpty())
        return;
    socket->write(strText.toUtf8());

}


