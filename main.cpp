#include <iostream>
#include <stdlib.h>
#include "animaux.h"

using namespace std;

int main() {
    srand(time(NULL));
    Attaque a1 = Attaque();
    Attaque a2 = Attaque(2);

    cout << "-------TEST ATTAQUE RANDOM ET PRÉVUE-------" << endl;
    cout << "Attaque random :" << endl;
    cout << a1.getTypeAttaque() << endl;
    cout << "Attaque prévue :" << endl;
    cout << a2.getTypeAttaque() << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
}