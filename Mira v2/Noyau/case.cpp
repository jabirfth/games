#include "case.h"

Case::Case()
{
    numero = 0;
    pOccupant = 0;
    transport = 0;
}

Case::Case(int num)
{
    numero = num;
    pOccupant = 0;
    transport = 0;
}

Case::~Case()
{
    pOccupant = 0;
}

void Case::placerPion(Pion* p)
{
    if(!estLibre() && numero < 100 && numero > 0)
        liberer();
    pOccupant=p;
    pOccupant->setPosition(numero);
}

void Case::liberer()
{
    if(estLibre())
        return;
    pOccupant->setPosition(0);
    pOccupant = 0;
}

int Case::getCaseDestination()
{
    return numero+transport;
}
