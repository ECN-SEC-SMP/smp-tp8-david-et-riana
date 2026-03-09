#include <stdlib.h>
#include <iostream>
#include "plateau.h"

using namespace std;

Plateau::Plateau(int longueur,int largeur){ 
    longueur_ = longueur ;
    largeur_ = largeur ;
}

int Plateau::getLongueur(){
    return longueur_;
}

int Plateau::getLargeur(){
    return largeur_;
}

void Plateau::affichePlateau(){
    //Initialisation du plateau
    for(int j = 0 ; j < getLongueur() ; j++){
    cout << "|" ;
    for (int i = 0 ; i < getLargeur() ; i++){
        cout << "----|";
    }
    cout << endl;
    for (int k=0 ; k< getLargeur()+1 ; k++){
        cout << "|    ";
    }
    cout << endl;
    }
    cout << "|" ;
    for (int i=0 ; i<10 ; i++){
        cout << "----|";
    }
    cout << endl;
    cout << endl;
}