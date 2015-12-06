#include "MyMainWindow.h"
#include <QApplication>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>

#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent)
{
    /*加菜单*/
    QMenuBar* pMenuBar = this->menuBar();
    menu = pMenuBar->addMenu("&File");
    //快捷键为Ctrl+O
    QAction* openAction = menu->addAction("Open", this, SLOT(slotOpen()), QKeySequence::Open);
    QAction* saveAction = menu->addAction("Save", this, SLOT(slotOpen()), QKeySequence::Save);
    //添加分割线
    menu->addSeparator();

    QAction* closeAction = menu->addAction("Exit", this, SLOT(close()), QKeySequence::Close);
    closeAction->setToolTip("close window");

    /* toolbar */
    QToolBar* toolBar = this->addToolBar("MyToolBar");
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(closeAction);

    /* status bar*/
    QStatusBar* pStatusBar = this->statusBar();
    pStatusBar->addWidget(label = new QLabel("Ok"));

    /* 别的控件占用了之后剩下的区域都是CentralWidget的 */
    view = new MyView;
    this->setCentralWidget(view);

    //系统托盘图标
    icon = new QSystemTrayIcon;
    icon->setIcon(QIcon("../icon/T13.ico"));
    icon->setToolTip("This is tray icon test");
    icon->show();
    icon->setContextMenu(menu);

    connect(icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));

    this->installEventFilter(this);
}

void MyMainWindow::paintEvent(QPaintEvent *)
{
    //起始点(0,0)会被菜单栏和工具栏覆盖，选择在View中操作
    QPainter p(this);
    p.drawText(10,10,"hello world");
}

void MyMainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::RightButton)
    //返回鼠标在屏幕的坐标，不能用ev->pos()
        menu->exec(QCursor::pos());
}

//TODO 无法实现阻止程序关闭后最小化
bool MyMainWindow::event(QEvent *ev)
{
    if(ev->type() == QEvent::Close)
    {
        return true;
    }
    return QMainWindow::event(ev);
}

//TODO 无法实现阻止程序关闭后最小化
bool MyMainWindow::eventFilter(QObject *o, QEvent *e)
{
    if(o == (QObject*)this && e->type() == QEvent::Close)
    {
        return false;
    }
    return QMainWindow::eventFilter(o, e);
}

void MyMainWindow::slotOpen()
{
    QString strFile = QFileDialog::getOpenFileName();
    qDebug() << "Open file is :" << strFile;
}

void MyMainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
    {
        if(this->isHidden())
            this->show();
        else
            this->hide();
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyMainWindow w;
    w.show();

    return app.exec();
}
