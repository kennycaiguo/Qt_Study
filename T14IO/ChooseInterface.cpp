#include "ChooseInterface.h"
#include <QNetworkInterface>
#include <QVBoxLayout>
ChooseInterface::ChooseInterface()
{
    /* get all interface*/
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
#if 0
    QList<QNetworkInterface> infList = QNetworkInterface::allInterfaces();
    QList<QNetworkAddressEntry> entryList = infList.at(0).addressEntries();
    entryList.at(0).broadcast();//...
#endif

    comboBox = new QComboBox();
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(comboBox);

    foreach (QHostAddress addr, addrList)
    {
        quint32 ipaddr = addr.toIPv4Address();
        if(ipaddr == 0)
            continue;
        comboBox->addItem(QHostAddress(ipaddr).toString());
    }
    connect(comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotComboBoxChange(QString)));
}

void ChooseInterface::slotComboBoxChange(QString str)
{
    strSelect = str;
}

