#include "partie.h"
#include <QString>

#include <iostream>
using namespace std;

Partie::Partie()
{
    joueurs = new Joueur[4];
    nbrJoueur = 0;
    gagnant = NULL;
}

void Partie::creerJoueur(std::string str,int clr)
{
    joueurs[nbrJoueur++] = Joueur(str,clr);
}

void Partie::preparerLePlateau(Joueur* Tjoueur)
{

    int Tclr[nbrJoueur];
    for(int i=0;i<nbrJoueur;i++)
    {
        Tclr[i] = Tjoueur[i].getCouleurPion();
    }

    plateau = Plateau_Du_Jeu(Tclr,nbrJoueur);
}


void Partie::commencerLaPartie()
{
    static int jCourant = 0;
    while(!gameOver())
    {
        static Joueur jr;
        jr = joueurs[jCourant];
        jeu j;
        j.valeur = jr.jouer();
        j.p = plateau.getPion(jr.getCouleurPion());
        plateau.effectuerLeJeu(j);

        if(plateau.getPion(jr.getCouleurPion())->estArrive())
            gagnant = &jr;

        if(!jr.aLeTour())
            jCourant++;

        if(jCourant==nbrJoueur)
            jCourant=0;
    }
}
