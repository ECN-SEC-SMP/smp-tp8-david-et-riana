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
    Plateau(int longueur,int largeur);
    int getLongueur() const;
    int getLargeur()  const;
    void affichePlateau() const;
    void ajouterAnimal(Animal *a);
};



#endif