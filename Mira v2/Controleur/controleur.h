#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "../Interfaces/fenetre_principale.h"
#include "../Noyau/partie.h"

//#include <QObject>

class Controleur : public QObject
{
    Q_OBJECT
public:
    Controleur(fenetre_principale *);
    Partie* getPartie() {return p;}
private:
    fenetre_principale *MainWindows;
    Partie *p;
    Joueur jr;
    jeu j;
    int jCourant;
    
public slots:
    void creer_partie();
    void creer_joueur(std::string,int);
    void preparerPlateau();
    void joueurCourant();
    void lancerDe();
    void retourDe();
    void testCase();

signals:
    void S_joueurCourant();
    void S_envoyerJCourant(int);
    void S_valeurDe(int);
    void S_valeurDeplacement(int,int);
    void DeplacementSup(int,int);
    void S_Gagnant(std::string);
    
};

#endif // CONTROLEUR_H
