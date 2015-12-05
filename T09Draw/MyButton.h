#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    MyButton(const QString& text, QWidget *parent = 0);
    ~MyButton(){}

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    QRect rect;
    QString text;
    bool pressed;


signals:
    void clicked();

public slots:
};

#endif // MYBUTTON_H
