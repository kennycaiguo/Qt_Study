#include "MyDialog.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

MyDialog::MyDialog()
{
    QPushButton* button = new QPushButton("Click", this);

    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClick()));

}

void MyDialog::paintEvent(QPaintEvent *)
{
    //TODO
}

void MyDialog::slotButtonClick()
{
#if 0
    QDialog* dlg = new QDialog;
    int ret;
    QPushButton* button = new QPushButton("dlg", dlg);

    connect(button, SIGNAL(clicked()), dlg, SLOT(accept()));

    ret = dlg->exec();  // 在模块对话框中，exec有自己的消息循环，并且把app的消息循环接管了
    // 如果Dialog是通过exec来显示，那么可以通过accept或者reject来关闭窗口
    // 如果Dialog是通过show来显示，那么可以通过close来关闭窗口，这个和QWidget一样的

    // 有许多特殊的dailog：文件选择，MessageBox，颜色选择，字体选择，打印预览，打印

    if(ret == QDialog::Accepted)
    {
        qDebug()<<"accepted";
    }

    if(ret == QDialog::Rejected)
    {
        qDebug()<< "rejected";
    }
#endif

#if 0
    QString strFilename = QFileDialog::getSaveFileName(NULL,
                                                       "Select file for save",
                                                       strDir,
                                                       "Png file (*.png)");
#endif

#if 0
    QString strFilename = QFileDialog::getOpenFileName(NULL,
                                                       "Select file for open",
                                                       strDir,
                                                       "Png file (*.png)");
#endif

#if 0
    //选择多个文件，返回string list
    //QFileDialog::getOpenFileNames()

    //选择目录
    QString strFilename = QFileDialog::getExistingDirectory();
    qDebug() << strFilename;

    QFileInfo fileinfo(strFilename);
    qDebug() << fileinfo.filePath();
#endif

#if 0
    QColorDialog color;
    color.exec();
    QColor c = color.selectedColor();
#endif

#if 0
    QFontDialog fontDialog;
    fontDialog.exec();
    QFont f = fontDialog.selectedFont();
#endif

    //waring question information
    //QMessageBox::critical(this, "Error", "Error message.....");

    //可以自己添加按钮
    int ret = QMessageBox::question(this, "???", "realy do ?",
                                    QMessageBox::Yes|QMessageBox::No|QMessageBox::YesAll);

    if(ret == QMessageBox::Yes)
    {
        qDebug()<<"yes i do";
    }
    else if (ret == QMessageBox::No)
    {
        qDebug()<<"no";
    }
}
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyDialog dlg;
    dlg.show();

    return app.exec();
}

