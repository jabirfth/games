#ifndef PARTIE_H
#define PARTIE_H

#include "plateau_du_jeu.h"
#include "joueur.h"

class Partie
{
public:
    Partie();
    void preparerLePlateau(Joueur*);
    void commencerLaPartie();
    Joueur* getJoueurs() { return joueurs; }
    int getNbrJoueurs() { return nbrJoueur; }
    void creerJoueur(std::string, int);
    bool gameOver() { return gagnant != NULL; }
    Joueur* getGagnant() { return gagnant; }
    void setGagnant(Joueur* j) {gagnant=j;}
    Plateau_Du_Jeu getPlateau() {return plateau;}

private:
    Plateau_Du_Jeu plateau;
    int nbrJoueur;
    Joueur *joueurs;
    Joueur *gagnant;
};

#endif // PARTIE_H
