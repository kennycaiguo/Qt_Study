#include <QCoreApplication>
#include "MySiganl.h"
#include "MySlot.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    MySiganl sig;
    MySlot slot;

    char c = 'a';

    QObject::connect(&sig, SIGNAL(sig()), &slot, SLOT(slot()));

    emit sig.sig();



    return app.exec();
}
