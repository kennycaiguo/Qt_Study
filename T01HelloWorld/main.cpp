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

    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));
    w.setWindowTitle("Hello World");

    w.show();

    return app.exec();
}
