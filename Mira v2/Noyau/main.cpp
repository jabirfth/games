#include <iostream>

using namespace std;

#include "partie.h"

int main()
{
    Partie p;
    p.creerJoueur("Jabir",1);
    p.creerJoueur("Chihab",2);
    p.creerJoueur("Chakib",3);
    p.creerJoueur("Aymane",4);
    p.preparerLePlateau(p.getJoueurs());
    p.commencerLaPartie();
    cout << "\n\n Felicitation " << p.getGagnant()->getPseudo() << " vous avez gagne" <<endl;
    return 0;
}

