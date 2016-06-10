#ifndef PION_H
#define PION_H

class Pion
{
public:
    Pion() { }
    Pion(int);
    int getCouleur() { return couleur; }
    int getPosition() { return position; }
    void setPosition(int n) { position=n; }
    bool estArrive() { return position == 100; }

private:
    int couleur;
    int position;
};

#endif // PION_H
