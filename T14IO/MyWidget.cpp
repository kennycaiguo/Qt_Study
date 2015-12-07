#include "MyWidget.h"
//#include <QIODevice>
#include <QApplication>
#include <QFile>
#include <QBuffer>
#include <QDebug>
#include <QLabel>
#include <QPixmap>

#include <QTextStream>
#include <QDataStream>
/*
 * QIODevice的子类
 * QFile
 * QBuffer  //memory file
 * QTcpSocket
 * QUdpSocket
 *
 * QDataStream  //io method
 * QTextStream
*/

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
#if 0
    QFile file("../T14IO/MyTest.txt");
    //删除文件
    //file.remove();
    file.open(QIODevice::ReadWrite);

    file.write("abc");
    //file.seek();
    file.close();
#endif

#if 0
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);//不需要路径，直接写到内存里

    buffer.write("abc");
    buffer.write("qwertyu");
    buffer.close();

    qDebug()<<buffer.buffer();
#endif

#if 0
    //发送图片到buffer中
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QPixmap pixmap("../image/aaa.png");
    pixmap.save(&buffer, "PNG"); //保存为PNG格式
    buffer.close();

    qDebug()<< buffer.buffer().size();

    //从buffer中接收图片
    QPixmap pixmap2;
    pixmap2.loadFromData(buffer.buffer(), "PNG");

    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap2);
#endif

#if 0
    QFile file("../T14IO/testStream.txt");
    file.open(QIODevice::ReadWrite);

    QTextStream textStream(&file);
    textStream << 1 << "abc" << 1.2;

    file.close();
#endif

#if 0
    QFile file("../T14IO/dataStream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);
    //人无法识别，但是方便读取
    dataStream << 1 << "abc" << 1.2 << QString("abc")<< QPoint(1, 1);
    file.close();
#endif

#if 0
    QFile file("../T14IO/dataStream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);

    int i;
    char *buf = new char[3];
    double d;
    QString str;
    QPoint pt;
    //方便读取
    dataStream >> i >> buf >> d >> str >>pt;

    qDebug()<< i << buf << d << str << pt;
    file.close();
    delete[] buf;
#endif

    //虚拟内存
    QFile file("../T14IO/map.txt");

    file.open(QIODevice::ReadWrite);

    file.resize(64*1024);

    //file.seek(65535);
    //file.write("1");
   // file.close();
    //file.open(QIODevice::ReadWrite);

    uchar* ptr = file.map(0, 64*1024);
    *ptr = 'a';
    ptr[1] = 'b';

    file.unmap(ptr);
    file.close();


}


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
