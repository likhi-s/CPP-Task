#include <QCoreApplication>
#include <QDebug>
#include "Message.h"
#include "Point.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QDebug dbg = qDebug();
    dbg << "Start:";
    dbg << Message("Hello Qt");
    dbg << Point(10);
    dbg << Point("Likhitha");


    // qDebug() << "Start:";
    // qDebug() << Message("Hello Qt");
    // qDebug() << Point(10);


    return 0;
}
