#include "MyWidget.h"
#include "MyApplication.h"
#include <QPushButton>
#include <QEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    button = new QPushButton("This Button", this);

    connect(button, SIGNAL(clicked()), this, SLOT(close()));

    //button给自己安装一个消息过滤器，经过button的消息都先调用过滤器的evenFilter函数
    button->installEventFilter(this);
}

bool MyWidget::eventFilter(QObject *o, QEvent *e)
{
//    if(o == (QObject*)button && (e->type() == QEvent::MouseButtonPress|| e->type() == QEvent::MouseButtonDblClick))
//    {
//        return true;
//        //return false表示不过滤
//    }

    return QWidget::eventFilter(o, e);
}

bool MyWidget::event(QEvent *e)
{
    if(e->type() == QEvent::User)
    {
        qDebug()<<"User event";
    }

    return QWidget::event(e);
}


int main(int argc, char* argv[])
{
    MyApplication app(argc, argv);

    MyWidget w;

    w.show();
    //发送一个Event给Mywidget
    //还有sendEvent
    //postEvent是把消息放到缓存区，可能不会立即处理
    //sendEvent会立即执行
    app.postEvent(&w, new QEvent(QEvent::User));

    return app.exec();
}
