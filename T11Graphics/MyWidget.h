#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
//场景
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPrinter>
//display scene
#include <QGraphicsView>

#include <QGraphicsItemAnimation>
//定时器
#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget(){}
    void paintEvent(QPaintEvent *);

    //场景
    QGraphicsScene* scene;  //data model
    QGraphicsView* view;   //show data model

    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);

    QTimer* timer;


signals:

public slots:
    void slotPaintRequested(QPrinter *printer);
    void slotTimeOut();
};

#endif // MYWIDGET_H
