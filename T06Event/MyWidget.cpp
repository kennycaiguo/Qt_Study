#include "MyWidget.h"

#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* lay = new QVBoxLayout(this);
//    button = new QPushButton("Button", this);
//    this->setMouseTracking(true);
//    button->setMouseTracking(true);

//    button->setDefault(true);

//    connect(button, SIGNAL(clicked()), this, SLOT(print()));
    lay->addWidget(edit = new QLineEdit());
    lay->addWidget(new QPushButton("OK"));

    connect(edit, SIGNAL(returnPressed()), this, SLOT(print()));

}

/* 截取消息 一般不用来处理 */
/* 也可以不重载 */
bool MyWidget::event(QEvent *ev)
{
    //鼠标点击消息被截断
//    if(ev->type() == QEvent::MouseButtonPress)
//        return ture;
    return QWidget::event(ev);
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
//    QPoint pt = ev->pos();
//    qDebug()<<pt;
//    if(ev->button() == Qt::LeftButton)
//    {

//    }
//    //伴随键 shift ctrl alt...
//    if(ev->modifiers() == Qt::ShiftModifier)
//    {
//        qDebug()<< "shift press";
//    }
    if(ev->modifiers() == Qt::ControlModifier)
    {
        //handle1 with Control
        return;
    }
    //handle2 without Control

}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{

}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    static int i = 0;
    qDebug()<<"mouse move" << i++;
}

void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    int key = ev->key();
    qDebug()<<key;
}

void MyWidget::keyReleaseEvent(QKeyEvent *ev)
{

}

void MyWidget::print()
{
    QLineEdit* edit = (QLineEdit*)sender();
    qDebug() << edit->text();
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;

    w.show();

    return app.exec();
}
