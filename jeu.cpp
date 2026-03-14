#include <iostream>
#include <stdlib.h>
#include "plateau.h"
#include "jeu.h"

using namespace std;

void Jeu::partie(int largeur_plateau, int longueur_plateau){
    char b;
    bool cont;
    Plateau p = Plateau(largeur_plateau, longueur_plateau);
    cout << "Voulez-vous continuer la partie? [y/n]" << endl;
    cin >> b ;
    if (b=='y'){
        cont = true;
    }
    else{
        cont = false;
    }
    while (cont){
        //mettre le plateau mis à jour à chaque fois + présenter les combats
    }

}