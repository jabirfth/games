#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H

#include <QMainWindow>

#include "PlateauDuJeu/glwidget.h"
#include "Menus/menu_accueil.h"
#include "Panels/panel_creationjrs.h"
#include "Panels/panel_infosjrs.h"
#include "Panels/panel_horloge.h"
#include "Panels/panel_de.h"
#include "Menus/menu_pause.h"

class Controleur;

namespace Ui {
    class fenetre_principale;
}

class fenetre_principale : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit fenetre_principale(QWidget *parent = 0);
    ~fenetre_principale();


    QGridLayout *layout;

    GLWidget *wdg_OpenGl;
    menu_accueil *menu1;
    menu_pause *menu2;
    panel_creationJrs *p_creatJrs;
    panel_InfosJrs *p_infoJrs;
    panel_Horloge *horloge;
    panel_de *p_de;

    Controleur *ctrl;



public slots:
    void afficher_menu_accueil();
    void afficher_menu_pause();
    void afficher_panel_creationJrs();
    void initialiser_plateauDuJeu(std::string,std::string);
    void commencer_partie();
    void recevoirJCourant(int);
    void de_a_lancer();
    void valeurDe_received(int);
    void valeurDeplacementN(int,int);
    void findepelacementN(int,int);
    void valeurDeplacementS(int,int);
    void Gagner(std::string);
    void pause_game(bool);

signals:
    void S_creer_partie();
    void S_creer_joueur(std::string,int);
    void S_commencer_partie();
    void S_JCourant(int);
    void S_de_a_lancer();
    void S_de_lance(int);
    void S_finanimation();
    void S_findeplacementN();

private:
    Ui::fenetre_principale *ui;
};

#endif // FENETRE_PRINCIPALE_H
