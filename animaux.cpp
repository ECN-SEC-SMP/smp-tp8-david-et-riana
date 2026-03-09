#include <iostream>
#include "animaux.h"

using namespace std;

Attaque::Attaque(){
    attaque_ = static_cast<attaque_e> (random()%3);
}

Attaque::Attaque(int a){
    attaque_ = static_cast<attaque_e> (a%3);
}

attaque_e Attaque::getTypeAttaque() const{ //On change le type de retour prck on a implémenté un enum
    return attaque_; 
}

ostream& operator<<(ostream &os, const attaque_e &a){
        switch (a)
    {
    case attaque_e::pierre :
         os << "pierre" ;
    break;

    case attaque_e::feuille :
         os << "feuille" ;
    break;

    case attaque_e::ciseaux :
         os << "ciseaux" ;

    break;

    default:
        break;
    }
    return os;
}





