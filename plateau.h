#ifndef SMP_TP8_DAVID_RIANA_PLATEAU_H
#define SMP_TP8_DAVID_RIANA_PLATEAU_H

#include <iostream>
#include<vector>
#include "animaux.h"

using namespace std;

class Plateau{
    int longueur_;
    int largeur_;
    vector<Animal*> animals_;
public:
    Plateau(int largeur,int longueur);
    int getLongueur() const;
    int getLargeur()  const;
    const vector<Animal*>& getAnimals() const;
    void affichePlateau() const;
    void ajouterAnimal(Animal *a);
    Animal* getAnimalAtIndex(int i)     const;
    void afficheAnimals() const;
    int  nbAnimalEnVie() const;
    void afficherNbAnimalEnVie() const;
    bool estCaseVide(int x,int y) const;

};

#endif