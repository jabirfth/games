#include <QApplication>

#include "Interfaces/fenetre_principale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetre_principale w;

    w.showFullScreen();
    
    return a.exec();
}
