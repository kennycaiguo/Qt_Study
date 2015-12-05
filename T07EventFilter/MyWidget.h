#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget(){}

    bool eventFilter(QObject *o, QEvent *e);

    bool event(QEvent *e);

    QPushButton* button;
signals:

public slots:
};

#endif // MYWIDGET_H
