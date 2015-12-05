#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QVector>
#include "MyButton.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget(){}

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

    MyButton* button;
    QVector<QVector<QPoint> > lines;

signals:

public slots:
    void slotButtonClicked();
};

#endif // MYWIDGET_H
