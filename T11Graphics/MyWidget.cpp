#include "MyWidget.h"

#include <QApplication>

#include <QTimeLine>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
//打印预览
#include <QPrintPreviewDialog>
//打印
#include <QPrintDialog>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

    QGraphicsLineItem* lineItem;
    QGraphicsTextItem* textItem;
    QGraphicsPixmapItem* pixmapItem;

    view = new QGraphicsView(this);

    view->setScene(scene = new QGraphicsScene);

    //设置QGraphicsView为背景透明，结合paintEvent可以实现两层效果
    view->setStyleSheet("background: transparent");

    scene->setSceneRect(0,0,480,272);

    scene->addItem(lineItem = new QGraphicsLineItem(0, 0, 200, 200));
    scene->addItem(textItem = new QGraphicsTextItem("Hello World"));
    //scene->addItem(pixmapItem = new QGraphicsPixmapItem(QPixmap("../aaa.png")));

    textItem->setPos(QPointF(100, 100));

   // textItem->setFont(QFont("aaa", 50, 700, true));



   // pixmapItem->setPos(100,100);

    //Animation 动画效果
    QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
  //  animation->setItem(pixmapItem);
    animation->setItem(textItem);
    //how to move
    QTimeLine* timeline = new QTimeLine(3000);
    timeline->setLoopCount(5);

    animation->setTimeLine(timeline);
    //设置移动效果
    animation->setTranslationAt(1, 100, 100);

    timeline->start();

    //timer = new QTimer();
    //设置超时时间,不停重复
//    timer->setInterval(1000);
//    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
//    timer->start();
    //仅设置一次
    //QTimer::singleShot(1000, this, SLOT(slotTimeOut()));


}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawLine(100,200,200,300);
}

void MyWidget::resizeEvent(QResizeEvent *)
{
    //view->setGeometry(QRect(QPoint(0, 0), QPoint(480, 272)));
}

void MyWidget::mousePressEvent(QMouseEvent *e)
{
    QDateTime datetime;
    QString str;
    str = "../" + datetime.currentDateTime().toString("yyyyMMdd-hhmmss") + ".png";
    if(e->button() == Qt::RightButton)
    {
//        QPixmap pixmap(size());
//        QPainter painter(&pixmap);
//        //Pixmap默认黑色背景，先画白色背景
//        painter.fillRect(QRect(0, 0, this->width(), this->height()), Qt::white);
//        //view->render();
//        scene->render(&painter);
//        pixmap.save(str);

        //打印预览
//        QPrintPreviewDialog dlg;
//        connect(&dlg, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slotPaintRequested(QPrinter *)));
//        dlg.exec();
        //打印
        QPrintDialog dlg;
        connect(&dlg, SIGNAL(accepted(QPrinter*)), this, SLOT(slotpaintRequested(QPrinter *printer)));
        dlg.exec();
    }
}

void MyWidget::slotPaintRequested(QPrinter *printer)
{
    QPainter painter(printer);

    scene->render(&painter);
    //painter.drawText();
}

void MyWidget::slotTimeOut()
{
    qDebug()<<"Timer Out";
}


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;



    //w.showMaximized();

    w.show();

    return app.exec();
}
