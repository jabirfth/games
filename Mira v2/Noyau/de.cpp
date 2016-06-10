#include "de.h"

#include <ctime>
#include <cstdlib>

De::De()
{
}

int De::lancer()
{
    static bool first=true;
    if(first)
    {
        srand(time(NULL));
        first = false;
    }
    return rand()%6 +1;
}
