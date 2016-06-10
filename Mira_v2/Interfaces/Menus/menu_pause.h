#ifndef MENU_PAUSE_H
#define MENU_PAUSE_H

#include <QtGui>

class menu_pause
{
public:
    menu_pause(QWidget*, QMainWindow*);
    ~menu_pause();

    void afficher_menu_pause(QGridLayout*);

private:
    QPushButton *btn_Reprendre;
    QPushButton *btn_nouvelle;
    QPushButton *btn_Accueil;
    QPushButton *btn_Exit;
    QVBoxLayout *layout;

    QWidget *parent;
    QMainWindow *mainWindow;
};


#endif // MENU_PAUSE_H
