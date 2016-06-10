#ifndef PLATEAU_DU_JEU_H
#define PLATEAU_DU_JEU_H

#include "Damier.h"
#include "de.h"

typedef struct {
    Pion* p;
    int valeur;
} jeu;

class Plateau_Du_Jeu
{
public:
    Plateau_Du_Jeu() { };
    Plateau_Du_Jeu(int*,int);
    Pion* getPion(int);
    Damier getDamier(){return damier;}
    void effectuerLeJeu(jeu);
    bool echelle_serpent(jeu j){return damier.echelle_serpent(j.p);}
private:
    Damier damier;
    Pion *pions;    

    void creerDamier();
    void creerPion(int);
};

#endif // PLATEAU_DU_JEU_H
