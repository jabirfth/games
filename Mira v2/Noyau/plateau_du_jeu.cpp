#include "plateau_du_jeu.h"

Plateau_Du_Jeu::Plateau_Du_Jeu(int* clr,int count)
{
    creerDamier();
    pions = new Pion[count];
    for(int i=0;i<count;i++)
        creerPion(clr[i]);
}

void Plateau_Du_Jeu::creerDamier()
{
    damier=Damier();
}

void Plateau_Du_Jeu::creerPion(int clr)
{
    static int i=0;
    pions[i++] = Pion(clr);
}

Pion* Plateau_Du_Jeu::getPion(int clr)
{
    for(int i=0;true;i++)
        if(pions[i].getCouleur() == clr)
            return &pions[i];
    return 0;
}


void Plateau_Du_Jeu::effectuerLeJeu(jeu j)
{
    damier.deplacerPion(j.p,j.valeur);
}
