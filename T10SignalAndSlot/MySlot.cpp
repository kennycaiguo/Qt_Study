#include "MySlot.h"
#include <QDebug>

MySlot::MySlot(QObject *parent) : QObject(parent)
{

}

MySlot::~MySlot()
{

}

void MySlot::slot()
{
    qDebug()<< "my slot";
}

