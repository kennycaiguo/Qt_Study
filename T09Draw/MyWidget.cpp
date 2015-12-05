#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    button = new MyButton("MyButton", this);

    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    for(int i = 0; i < lines.size(); ++i )
    {
        const QVector<QPoint>& line = lines.at(i);
        for(int j = 0; j < line.size() - 1; ++j)
        {
            p.drawLine(line.at(j), line.at(j+1));
        }

    }
//    for(int i = 0; i < this->line.size()-1; ++i)
//    {
//        p.drawLine(line.at(i), line.at(i+1));
//    }
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    QVector<QPoint> line;

    lines.append(line);

    QVector<QPoint>& lastLine = lines.last();

    lastLine.append(ev->pos());

}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    QVector<QPoint>& lastLine = lines.last();

    lastLine.append(ev->pos());
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(lines.isEmpty())
    {
        QVector<QPoint> line;

        lines.append(line);
    }
    QVector<QPoint>& lastLine = lines.last();

    lastLine.append(ev->pos());
    update();
}

void MyWidget::slotButtonClicked()
{
    qDebug()<<"button is clicked";
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;

    w.show();

    return app.exec();
}

