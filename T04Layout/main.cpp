
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget w;

    QPushButton button;
    button.setText("Button");
   // button.setParent(&w);

    QLineEdit edit;
  //  edit.setParent(&w);

#if 0
    QHBoxLayout layout;
    layout.addWidget(&button,1);
    layout.addWidget(&edit,1);
    layout.addStretch(1);
#endif

#if 0
    QGridLayout layout;
    layout.setColumnStretch(3, 1);
    layout.setRowStretch(4, 1);
    layout.setColumnStretch(0, 1);
    layout.setRowStretch(0, 1);

    layout.addWidget(&button, 1, 1);
    layout.addWidget(&edit, 1, 2);
    layout.addWidget(new QPushButton("aaa"), 2, 1);
    layout.addWidget(new QPushButton("bbb"), 2, 2);
    /*在第三行，第一列插入按钮，占1行两列的位置*/
    layout.addWidget(new QPushButton("ccc"), 3, 1, 1, 2);
#endif
    QGridLayout layout;
    QLineEdit* password;
    layout.setColumnStretch(3, 1);
    layout.setRowStretch(4, 1);
    layout.setColumnStretch(0, 1);
    layout.setRowStretch(0, 1);

    layout.addWidget(new QLabel("Username:"), 1, 1);
    layout.addWidget(new QLineEdit(), 1, 2);
    layout.addWidget(new QLabel("Password:"), 2, 1);
    layout.addWidget(password = new QLineEdit(), 2, 2);

    password->setEchoMode(QLineEdit::Password);

    QHBoxLayout* hBox;
    layout.addLayout(hBox = new QHBoxLayout, 3, 2);
    hBox->addStretch(1);
    hBox->addWidget(new QPushButton("登录"));



    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));
    w.setWindowTitle("Hello World");

    w.setLayout(&layout);
    w.show();

    return app.exec();
}
