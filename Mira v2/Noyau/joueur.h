#ifndef JOUEUR_H
#define JOUEUR_H

#include <cstdlib>
#include <QString>

class Joueur
{
public:
    Joueur() { }
    Joueur(std::string, int);
    std::string getPseudo() { return pseudo; }
    int getCouleurPion() { return clrPion; }
    bool aLeTour() { return active; }
    bool aGagne() { return gagnant; }
    void setGagnant() { gagnant = true; }
    int jouer();
    int lancerLeDe();

private:
    int clrPion;
    std::string pseudo;
    bool active;
    bool gagnant;
};

#endif // JOUEUR_H
