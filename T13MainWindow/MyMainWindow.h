#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "MyView.h"
//系统托盘图标
#include <QSystemTrayIcon>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);
    QLabel* label;
    MyView* view;
    QMenu* menu;
    QSystemTrayIcon* icon;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *ev);
    bool event(QEvent *ev);
    bool eventFilter(QObject *o, QEvent *e);

signals:

public slots:
    void slotOpen();
    void slotActivated(QSystemTrayIcon::ActivationReason reason);
public slots:
};

#endif // MYMAINWINDOW_H
