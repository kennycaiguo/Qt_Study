#ifndef CHOOSEINTERFACE_H
#define CHOOSEINTERFACE_H
#include <QDialog>
#include <QComboBox>

class ChooseInterface : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseInterface(/*QWidget *parent = 0*/);
    QComboBox* comboBox;
    QString strSelect;
public slots:
    void slotComboBoxChange(QString str);
};

#endif // CHOOSEINTERFACE_H
