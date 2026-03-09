#include <iostream>
#include <stdlib.h>
#include "animaux.h"

using namespace std;

int main() {
    srand(time(NULL));
    Attaque a1 = Attaque();
    switch (a1.getTypeAttaque())
    {
    case attaque_e::pierre :
         cout << "pierre" <<endl ;
    break;

    case attaque_e::feuille :
         cout << "feuille" <<endl ;
    break;

    case attaque_e::ciseaux :
         cout << "ciseaux" <<endl ;

    break;

    default:
        break;
    }

    return 0;
}