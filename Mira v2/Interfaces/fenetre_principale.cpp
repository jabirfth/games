#include "fenetre_principale.h"
#include "ui_fenetre_principale.h"
#include "Controleur/controleur.h"

fenetre_principale::fenetre_principale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetre_principale)
{
    ctrl = new Controleur(this);
    ui->setupUi(this);
    wdg_OpenGl = new GLWidget(this,this);
    centralWidget()->layout()->addWidget(wdg_OpenGl);

    layout = new QGridLayout(wdg_OpenGl);

    menu1 = new menu_accueil(wdg_OpenGl,this);
    menu1->afficher_menu_accueil(layout);
}

void fenetre_principale::afficher_menu_accueil()
{
    menu1 = new menu_accueil(wdg_OpenGl,this);
    menu1->afficher_menu_accueil(layout);
}

void fenetre_principale::afficher_menu_pause()
{
    menu2 = new menu_pause(wdg_OpenGl,this);
    menu2->afficher_menu_pause(layout);
}

void fenetre_principale::afficher_panel_creationJrs()
{
    connect(this,SIGNAL(S_creer_partie()),ctrl,SLOT(creer_partie()));
    emit S_creer_partie();
    disconnect(SIGNAL(S_creer_partie()));
    delete menu1;

    p_creatJrs = new panel_creationJrs(wdg_OpenGl,this);
    p_infoJrs = new panel_InfosJrs(wdg_OpenGl,this);
    horloge = new panel_Horloge(wdg_OpenGl,this);
    p_de = new panel_de(wdg_OpenGl,this);

    p_infoJrs->afficher_panel_infoJrs(layout,false);
    horloge->afficher_panel_horloge(layout,false);
    p_de->afficher_panel_de(layout,false);
    p_creatJrs->afficher_panel_creationJrs(layout);
}

void fenetre_principale::initialiser_plateauDuJeu(std::string psd, std::string clr)
{
    connect(this,SIGNAL(S_creer_joueur(std::string,int)),ctrl,SLOT(creer_joueur(std::string,int)));
    int a = 0;
    if(clr=="Vert")
        a=1;
    else if(clr=="Jaune")
        a=2;
    else if(clr=="Bleu")
        a=3;
    else if(clr=="Marron")
        a=4;

    static bool first = true;
    if(first)
    {
        p_infoJrs = new panel_InfosJrs(wdg_OpenGl,this);

        p_infoJrs->afficher_panel_infoJrs(layout);
        p_infoJrs->enrouler();
        first=false;
    }
    p_infoJrs->creer_ficheJr(QString::fromStdString(psd),a);
    wdg_OpenGl->damier->creerPion(a);

    emit S_creer_joueur(psd,a);
    disconnect(SIGNAL(S_creer_joueur(std::string,int)));
}

void fenetre_principale::commencer_partie()
{
    connect(this,SIGNAL(S_commencer_partie()),ctrl,SLOT(preparerPlateau()));
    emit S_commencer_partie();

    delete p_creatJrs;
    delete horloge;
    delete p_de;
    p_de = new panel_de(wdg_OpenGl,this);    
    horloge = new panel_Horloge(wdg_OpenGl,this);
    p_infoJrs->enrouler();
    horloge->afficher_panel_horloge(layout);
    horloge->setTimerOnOff(true);
    p_de->afficher_panel_de(layout);

    wdg_OpenGl->setEtat(IN_GAME);
}

void fenetre_principale::recevoirJCourant(int clr)
{
    p_de->enable_btn();
    connect(this,SIGNAL(S_JCourant(int)),p_infoJrs,SLOT(selectionner_tab(int)));
    emit S_JCourant(clr);
    disconnect(SIGNAL(S_JCourant(int)));
}

void fenetre_principale::de_a_lancer()
{
    connect(this,SIGNAL(S_de_a_lancer()),ctrl,SLOT(lancerDe()));
    emit S_de_a_lancer();
    disconnect(SIGNAL(S_de_a_lancer()));
}

void fenetre_principale::valeurDe_received(int val)
{
    connect(wdg_OpenGl,SIGNAL(S_finanimation()),ctrl,SLOT(retourDe()));
    wdg_OpenGl->setValeurDe(val);
    wdg_OpenGl->afficher_de();
}

void fenetre_principale::valeurDeplacementN(int i,int clr)
{
    wdg_OpenGl->setPosTo(i);
    wdg_OpenGl->setId_Pion(clr);
    wdg_OpenGl->deplacer();
    wdg_OpenGl->damier->setdeplacer();
}

void fenetre_principale::findepelacementN(int id,int pos)
{
    p_infoJrs->update_info(id,pos);
    connect(this,SIGNAL(S_findeplacementN()),ctrl,SLOT(testCase()));
    emit S_findeplacementN();
    disconnect(SIGNAL(S_findeplacementN()));
}

void fenetre_principale::valeurDeplacementS(int i,int clr)
{
    wdg_OpenGl->setPosTo(i);
    wdg_OpenGl->setId_Pion(clr);
    wdg_OpenGl->deplacer();
    wdg_OpenGl->damier->setdeplacerS();
}


void fenetre_principale::Gagner(std::string psd)
{
//    QMessageBox::information(wdg_OpenGl,"Felicitation !!"
//                             ,"Felicitation " + psd + " vous avez gagné !! \n " +
//                             "Cliquez sur le bouton OK pour revenire au menu principal");
    delete p_infoJrs;
    delete horloge;
    delete p_de;
    wdg_OpenGl->setEtat(INITIAL);

    menu1 = new menu_accueil(wdg_OpenGl,this);
    menu1->afficher_menu_accueil(layout);
}

void fenetre_principale::pause_game(bool on)
{
    horloge->setTimerOnOff(on);
    wdg_OpenGl->set_timerOnOff(on);
}


fenetre_principale::~fenetre_principale()
{
    delete ui;
}


