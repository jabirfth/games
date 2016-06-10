#include "controleur.h"

Controleur::Controleur(fenetre_principale *wid)
{
    MainWindows=wid;
    jCourant=0;

    connect(this,SIGNAL(S_valeurDe(int)),MainWindows,SLOT(valeurDe_received(int)));

}

void Controleur::creer_partie()
{
    p = new Partie();
}

void Controleur::creer_joueur(std::string name,int clr)
{
    p->creerJoueur(name,clr);
}

void Controleur::preparerPlateau()
{
    p->preparerLePlateau(p->getJoueurs());
    connect(this,SIGNAL(S_joueurCourant()),this,SLOT(joueurCourant()));
    emit S_joueurCourant();
}

void Controleur::joueurCourant()
{
        if(!p->gameOver())
        {
            jr = p->getJoueurs()[jCourant];
        }
        else
            return;

        connect(this,SIGNAL(S_envoyerJCourant(int)),MainWindows,SLOT(recevoirJCourant(int)));
        emit S_envoyerJCourant(jr.getCouleurPion());
        disconnect(SIGNAL(S_envoyerJCourant(int)));
}

void Controleur::lancerDe()
{
    j.valeur = jr.jouer();
    j.p = p->getPlateau().getPion(jr.getCouleurPion());
    emit S_valeurDe(j.valeur);
}

void Controleur::retourDe()
{
    p->getPlateau().effectuerLeJeu(j);

    connect(this,SIGNAL(S_valeurDeplacement(int,int)),MainWindows,SLOT(valeurDeplacementN(int,int)));
    emit S_valeurDeplacement(j.p->getPosition(),j.p->getCouleur());
    disconnect(SIGNAL(S_valeurDeplacement(int,int)));

    if(p->getPlateau().getPion(jr.getCouleurPion())->estArrive())
    {
        p->setGagnant(&jr);
        connect(this,SIGNAL(S_Gagnant(std::string)),MainWindows,SLOT(Gagner(std::string)));
        emit S_Gagnant(jr.getPseudo());
        disconnect(SIGNAL(S_Gagnant(std::string)));
    }
    if(!jr.aLeTour())
        jCourant++;

    if(jCourant==p->getNbrJoueurs())
        jCourant=0;
}

void Controleur::testCase()
{
    connect(this,SIGNAL(DeplacementSup(int,int)),MainWindows,SLOT(valeurDeplacementS(int,int)));
    if(p->getPlateau().echelle_serpent(j))
    {
        emit DeplacementSup(j.p->getPosition(),j.p->getCouleur());
        disconnect(SIGNAL(DeplacementSup(int,int)));
        emit S_joueurCourant();
    }
    else
        emit S_joueurCourant();
}
