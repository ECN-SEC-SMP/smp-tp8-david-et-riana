#ifndef SMP_TP8_DAVID_RIANA_JEU_H
#define SMP_TP8_DAVID_RIANA_JEU_H

#include <iostream>
#include <stdlib.h>
#include "plateau.h"

using namespace std;

class Jeu{
    private : 
    Plateau plateau_ ;
    public:
    Jeu(Plateau& p);
    void partie(int largeur_plateau, int longueur_plateau);
};

#endif
