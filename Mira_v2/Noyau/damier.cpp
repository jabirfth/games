#include "damier.h"
#include "case.h"

#include <iostream>
using namespace std;

Damier::Damier()
{
    cases = new Case[101];
    creerCases();
}

void Damier::creerCases()
{
    for(int i=0;i<=100;i++)
    {
        switch(i)
        {
        case 1: //38
            cases[i] = creerSerpent_Echelle(i,38);
            break;
        case 4:  //14
            cases[i] = creerSerpent_Echelle(i,14);
            break;
        case 8: //31
            cases[i] = creerSerpent_Echelle(i,31);
            break;
        case 16: //6
            cases[i] = creerSerpent_Echelle(i,6);
            break;
        case 21: //42
            cases[i] = creerSerpent_Echelle(i,42);
            break;
        case 28 : //84
            cases[i] = creerSerpent_Echelle(i,84);
            break;
        case 36: //44
            cases[i] = creerSerpent_Echelle(i,44);
            break;
        case 47://26
            cases[i] = creerSerpent_Echelle(i,26);
            break;
        case 49://11
            cases[i] = creerSerpent_Echelle(i,11);
            break;
        case 51: //67
            cases[i] = creerSerpent_Echelle(i,67);
            break;
        case 56://53
            cases[i] = creerSerpent_Echelle(i,53);
            break;
        case 62://19
            cases[i] = creerSerpent_Echelle(i,19);
            break;
        case 64://60
            cases[i] = creerSerpent_Echelle(i,60);
            break;
        case 71: //91
            cases[i] = creerSerpent_Echelle(i,91);
            break;
        case 80: //100
            cases[i] = creerSerpent_Echelle(i,100);
            break;
        case 87: //24
            cases[i] = creerSerpent_Echelle(i,24);
            break;
        case 93: //73
            cases[i] = creerSerpent_Echelle(i,73);
            break;
        case 95: //75
            cases[i] = creerSerpent_Echelle(i,75);
            break;
        case 98: //78
            cases[i] = creerSerpent_Echelle(i,78);
            break;
        default:
            cases[i] = Case(i);
            break;
        }
    }
}

Case Damier::creerSerpent_Echelle(int posFrom,int posTo)
{
    Case c(posFrom);
    c.setValeuTransport(posTo-posFrom);
    return c;
}

void Damier::deplacerPion(Pion* p,int valDe)
{
    int pos = p->getPosition();
    int posTo = pos + valDe;
    cout << "   |***" << pos << " **||** " << posTo << "***|";

    if(posTo > 100) {
        posTo = pos-posTo+100;
        cout << "reculer"; }

    cases[pos].liberer();
    cases[posTo].placerPion(p);
}

bool Damier::echelle_serpent(Pion* p)
{
    int pos=p->getPosition();
    if(cases[pos].getCaseDestination() != pos)
    {
        deplacerPion(p,cases[pos].getValeurTransport());
        return 1;
    }
    else
        return 0;
}
