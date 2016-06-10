#ifndef WDG_ACCUEIL_H
#define WDG_ACCUEIL_H

#include <QtGui>


class menu_accueil
{
public:
    menu_accueil(QWidget*, QMainWindow*);
    ~menu_accueil();

    void afficher_menu_accueil(QGridLayout*);

private:
    QPushButton *btn_JrVsJr;
    QPushButton *btn_JrVsOrdi;
    QPushButton *btn_LoadGame;
    QPushButton *btn_Rules;
    QPushButton *btn_Exit;

    QWidget *parent;
    QMainWindow *mainWindow;
};

#endif // WDG_ACCUEIL_H
