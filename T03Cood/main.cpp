#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget w;

    QPushButton button;
    button.setText("Button");
    button.setParent(&w);
    /*基于父对象的坐标值*/
    button.setGeometry(30,30,100,30);


    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));
    w.setWindowTitle("Hello World");
    w.show();

    return app.exec();
}
