#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPainter>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
