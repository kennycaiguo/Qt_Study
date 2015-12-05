#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    MyDialog();
    ~MyDialog(){}
    void paintEvent(QPaintEvent *);

    QString strDir;

public slots:
    void slotButtonClick();
};

#endif // MYDIALOG_H
