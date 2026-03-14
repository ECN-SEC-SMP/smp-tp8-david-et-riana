#include <iostream>
#include <stdlib.h>
#include "animaux.h"
#include "plateau.h"

using namespace std;

int main() {
    srand(time(NULL));

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

    // Test plateau
    const int maxX = 5;
    const int maxY = 6;
    auto p = Plateau(maxX,maxY);

    // Affichage du plateau vide
    p.affichePlateau();

    p.ajouterAnimal(new Loup(maxX, maxY, 1, 1));
    p.ajouterAnimal(new Lion(maxX, maxY, 2, 2));
    p.ajouterAnimal(new Ours(maxX, maxY, 3, 4));
    p.ajouterAnimal(new Pierre(maxX, maxY, 0, 3));

    // Affichage du plateau avec un Loup, un Lion, un Ours et une Pierre
    cout << "-------Plateau : Loup, Lion, Ours et Pierre -------" << endl;
    p.affichePlateau();

    return 0;
}