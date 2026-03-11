#include <iostream>
#include "plateau.h"

using namespace std;

Plateau::Plateau(int longueur,int largeur){ 
    longueur_ = longueur ;
    largeur_ = largeur ;
}

int Plateau::getLongueur() const {
    return longueur_;
}

int Plateau::getLargeur() const {
    return largeur_;
}

void Plateau::affichePlateau() const {
    //Initialisation du plateau

    // j représente la position en x
    // k représente la position en y

    for (int j = 0; j < getLongueur(); j++) {
        cout << "|";
        for (int i = 0; i < getLargeur(); i++) {
            cout << "----|";
        }
        cout << endl;
        for (int k = 0; k < getLargeur() + 1; k++) {
            cout << "|    ";
            if (k < getLargeur()) {
                for (Animal *a : animals_) {
                    if (a->getX() == j
                        && a->getY() == k
                        && a->getVivant()) {

                        cout << a->getChar() << "   ";
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    cout << "|";
    for (int i = 0; i < getLargeur(); i++) {
        cout << "----|";
    }
    cout << endl;
    cout << endl;
}

void Plateau::ajouterAnimal(Animal *a) {
    animals_.push_back(a);
}
