#ifndef MYSIGANL_H
#define MYSIGANL_H

#include <QObject>

class MySiganl : public QObject
{
    Q_OBJECT
public:
    explicit MySiganl(QObject *parent = 0);
    ~MySiganl();

signals:
    void sig();

public slots:
};

#endif // MYSIGANL_H
