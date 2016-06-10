#include "joueur.h"

#include "de.h"

Joueur::Joueur(std::string str, int clr)
{
    pseudo = str;
    clrPion = clr;
    active = false;
}

int Joueur::jouer()
{
    active = true;
    int val = lancerLeDe();
    if(val!=6)
        active = false;
    return val;
}

int Joueur::lancerLeDe()
{
    return De::lancer();
}
