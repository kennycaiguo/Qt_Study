#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>


class MyApplication : public QApplication
{
public:
    MyApplication(int argc, char* argv[]):QApplication(argc, argv){}
    ~MyApplication(){}
    bool notify(QObject *o, QEvent *e);
};

#endif // MYAPPLICATION_H
