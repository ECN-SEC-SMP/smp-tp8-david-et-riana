#ifndef SMP_TP8_DAVID_RIANA_PLATEAU_H
#define SMP_TP8_DAVID_RIANA_PLATEAU_H

#include <stdlib.h>
#include <iostream>

using namespace std;

class Plateau{
private:
    int longueur_ ;
    int largeur_ ;
public:
    Plateau(int longueur,int largeur);
    int getLongueur();
    int getLargeur();
    void affichePlateau();
};



#endif