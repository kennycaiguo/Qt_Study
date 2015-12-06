#include "MyView.h"
#include <QPainter>

MyView::MyView(QWidget *parent) : QWidget(parent)
{

}

void MyView::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //该区域会随着toolbar的变化而变化
    p.fillRect(rect(), Qt::red);
}

