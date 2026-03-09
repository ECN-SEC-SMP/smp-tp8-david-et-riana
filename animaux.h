#ifndef SMP_TP8_DAVID_RIANA_JEU_VIE_H
#define SMP_TP8_DAVID_RIANA_JEU_VIE_H

#include <stdlib.h>
#include <iostream>

using namespace std;

enum class attaque_e {
    pierre = 0,
    feuille = 1,
    ciseaux = 2
};

class Attaque{
    private : 
        attaque_e attaque_ ;
    public :
        //Attaque aléatoire
        Attaque();
        //Attaque spécifique
        Attaque(int a);

        //Getters
        attaque_e getTypeAttaque() const;

    
        
};

//Surcharge
ostream& operator<<(ostream &os, const attaque_e &a);

class Animal{

};

class Lion{

};

class Ours{

};

class Pierre{

};

class Loup{

};

#endif