#include "MyWidget.h"
#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QTextBrowser>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QCompleter>

#include <QVBoxLayout>
#include <QHBoxLayout>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label;
    QComboBox* combobox;
    QPushButton* button;
    QTextEdit* edit;
    QGroupBox* group;

    layout->addWidget(label = new QLabel("label"));
    layout->addWidget(button = new QPushButton("Button"));
    button->setStyleSheet("QPushButton {font:bold 20px;color:red}");

    layout->addWidget(new QRadioButton("Radio"));
    layout->addWidget(new QCheckBox("check box"));
    layout->addWidget(combobox = new QComboBox());


    combobox->addItem("Select item1");
    combobox->addItem("Select item2");
    combobox->setEditable(true);
    combobox->setCompleter(new QCompleter(QStringList()<< "aaa" << "bbb"));

    layout->addWidget(edit = new QTextEdit);
    edit->setText("wo shi xhc");

    layout->addWidget(group = new QGroupBox("group box"));
    QHBoxLayout* hBoxLay;
    group->setLayout(hBoxLay = new QHBoxLayout);
    hBoxLay->addWidget(new QPushButton("aaa"));
    hBoxLay->addWidget(new QPushButton("bbb"));

    QSlider* slider;
    layout->addWidget(slider = new QSlider(Qt::Horizontal));
    slider->setMaximum(100);
    slider->setMinimum(0);

    QSpinBox* spinbox;
    layout->addWidget(spinbox = new QSpinBox);
    spinbox->setMaximum(100);
    spinbox->setMinimum(0);

    connect(slider, SIGNAL(sliderMoved(int)), spinbox, SLOT(setValue(int)));
    layout->addWidget(new QDateTimeEdit);

}

MyWidget::~MyWidget()
{

}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;

    w.show();

    return app.exec();
}
