#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <qlogging.h>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::paintEvent(QPaintEvent *)
{
    qDebug()<< "sb";
    QPixmap pixmap(size());
    //pixmap默认背景是黑的
    QPainter p(&pixmap);

    //transform可以代替translate
    QTransform transform;
    //旋转角度
    //transform.rotate(30);
    //缩放
    transform.scale(0.5, 0.5);
    //旋转
    p.setTransform(transform);
    //平移变换
    p.translate(100, 100);
    //设置画笔
    p.setPen(QPen(Qt::red, 2, Qt::DashLine));
    //设置画刷，影响封闭图形内部
    p.setBrush(Qt::yellow);
    //设置字体
    p.setFont(QFont("aaa", 40, 700, true));
    //消除锯齿
    p.setRenderHint(QPainter::Antialiasing);
    //画直线
    p.drawLine(QPoint(0,0), QPoint(100,100));
    //画椭圆/圆
    p.drawEllipse(QPoint(95,300), 50, 50);
    //写文字
    p.drawText(QPoint(300,50),"哈喽");
    //画图片
    //p.drawPixmap(QPoint(40,40), QPixmap("../aaa.png"));
    //画矩形
    //p.drawRect(QRect(40,60,100,50));
    //画圆角矩形
    p.drawRoundRect(QRect(40, 60, 100, 50));

    p.end();

    p.begin(this);

    p.drawPixmap(0, 0, pixmap);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;

    w.show();

    return app.exec();
}

