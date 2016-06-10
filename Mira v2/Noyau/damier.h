#ifndef DAMIER_H
#define DAMIER_H

#include "case.h"

class Damier
{
public:
    Damier();
    void deplacerPion(Pion*, int);
    void creerCases();
    Case creerSerpent_Echelle(int,int);
    bool echelle_serpent(Pion*);
    Case* getCases(){return cases;}
private:
    Case *cases;
};

#endif // DAMIER_H
