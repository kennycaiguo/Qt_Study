#include <QCoreApplication>

#include "../T15Library/T15Library.h"


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    T15Library d;
    d.Encrypt();

    app.exec();
}
