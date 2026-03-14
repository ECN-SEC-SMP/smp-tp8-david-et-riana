#include <iostream>
#include "plateau.h"

using namespace std;

Plateau::Plateau(int largeur,int longueur){
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
    bool isAnimalPresent = false;
    Animal *animalTrouve = nullptr;

    // j représente la position en x
    // k représente la position en y

    for (int j = 0; j < getLongueur(); j++) {
        cout << "|";
        for (int i = 0; i < getLargeur(); i++) {
            cout << "----|";
        }
        cout << endl;
        for (int k = 0; k < getLargeur(); k++) {
            isAnimalPresent = false;

                for (Animal *a : animals_) {
                    if (a->getX() == k
                        && a->getY() == j
                        && a->getVivant()) {
                        isAnimalPresent = true;
                        animalTrouve = a;
                        break;
                    }
                }

                if (isAnimalPresent) {
                    cout << "| "  << animalTrouve->getChar() << " ";
                } else {
                    cout << "|    ";
                }
        }
        cout << "|" << endl;
    }
    cout << "|";
    for (int i = 0; i < getLargeur(); i++) {
        cout << "----|";
    }
    cout << endl;
}

void Plateau::ajouterAnimal(Animal *a) {
    animals_.push_back(a);
}

Animal * Plateau::getAnimalAtIndex(int i) const {
    return animals_.at(i);
}

void Plateau::afficheAnimals() const {
    for (Animal *a : animals_) {
        cout << *a << endl;
    }
}
