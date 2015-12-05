#include <QApplication>
#include <QCompleter>
#include <QWidget>
#include <QLineEdit>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget w;

    QLineEdit edit;
    edit.setParent(&w);
    /*输入密码模式*/
    //edit.setEchoMode(QLineEdit::Password);
    //密码提示
    //edit.setPlaceholderText("xhc");
    //获取输入的密码
    //edit.text();

    /*匹配*/
    QCompleter completer(QStringList()<< "abc" << "123" << "456");
    completer.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&completer);


    //QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));
    w.setWindowTitle("Hello World");
    w.show();

    return app.exec();
}
