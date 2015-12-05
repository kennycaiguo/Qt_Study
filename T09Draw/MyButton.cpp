#include "MyButton.h"
#include <QPainter>
#include <QMouseEvent>
MyButton::MyButton(QWidget *parent) :
    QWidget(parent), rect(0, 0, 100, 30)
{
    pressed = false;
    this->setGeometry(rect);
}

MyButton::MyButton(const QString &text, QWidget *parent):
    QWidget(parent), text(text), rect(0, 0, 100, 20)
{
    pressed = false;
    this->setGeometry(rect);
}

void MyButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(pressed)
        p.setBrush(Qt::yellow);
    else
        p.setBrush(Qt::darkGray);
    p.drawRect(rect);
    p.drawText(rect, text, QTextOption(Qt::AlignCenter));
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    pressed = true;
    update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    pressed = false;
    update();

    if(rect.contains(ev->pos()))
        emit clicked();
}


