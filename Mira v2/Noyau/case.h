#ifndef CASE_H
#define CASE_H

#include "pion.h"

class Case
{
public:
    Case();
    Case(int);
    ~Case();
    int getNumero() { return numero; }
    void placerPion(Pion*);
    Pion* getPionOccupant() { return pOccupant; }
    int getValeurTransport() { return transport; }
    void setValeuTransport(int n) { transport = n; }
    int getCaseDestination();    
    void liberer();
    bool estLibre() { return pOccupant == 0; }

private:
    int numero;
    Pion *pOccupant;
    int transport;
};

#endif // CASE_H
