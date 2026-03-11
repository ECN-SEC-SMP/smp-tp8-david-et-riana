#include <iostream>
#include <stdlib.h>
#include "animaux.h"
#include "plateau.h"

using namespace std;

int main() {
    srand(time(NULL));
    Plateau p = Plateau(5,6);
    p.affichePlateau();

    
// Test des attaques
    Attaque a1 = Attaque();
    Attaque a2 = Attaque(2);
    Attaque a3 = Attaque(1);
    Attaque a4 = Attaque(0);
    Attaque a5 = Attaque(2);

    cout << "-------TEST ATTAQUE RANDOM ET PRÉVUE-------" << endl;
    cout << "Attaque random :" << endl;
    cout << a1.getTypeAttaque() << endl;
    cout << "Attaque prévue :" << endl;
    cout << a2.getTypeAttaque() << endl;
    cout << "-------------------------------------------" << endl;

    cout << "-------TEST RESOLUTION ATTAQUE-------" << endl;
    cout << "Attaque gagnante pour a2 :" << endl;
    cout << a2.resoudreAttaque(a3) << endl;
    cout << "Attaque perdante pour a2 :" << endl;
    cout << a2.resoudreAttaque(a4) << endl;
    cout << "Attaque avec égalité :" << endl;
    cout << a2.resoudreAttaque(a5) << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
}