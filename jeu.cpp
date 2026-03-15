#include <iostream>
#include <stdlib.h>
#include "plateau.h"
#include "jeu.h"

using namespace std;

Jeu::Jeu(Plateau& p) : plateau_(p){}

void Jeu::partie(int largeur_plateau, int longueur_plateau){
    int compt =0;
    char b;
    bool cont = true;
    //Déclaration des abscisses et ordonnées pour chaque animaux (modifiés pour chaque instance)
    int x = 0;
    int y = 0;
    //Mise en place des animaux sur le plateau en remplissant 25% du plateau
    int nb_animaux = 0;
    nb_animaux = (longueur_plateau*largeur_plateau)/4;
    vector<Lion*> lions;
    vector<Ours*> ours;
    vector<Loup*> loups;
    vector<Pierre*> pierres;

    //Ajout des lions au plateau
    for(int i = 0; i < (nb_animaux/4); i++){
        x = random()%largeur_plateau;
        y = random()%longueur_plateau;
        while (!plateau_.estCaseVide(x,y))
        {
            x = random()%largeur_plateau;
            y = random()%longueur_plateau;
        }
        lions.push_back(new Lion(largeur_plateau, longueur_plateau, x, y));
    }
    for(Lion* l : lions){
    plateau_.ajouterAnimal(l);
    }

    //Ajout des ours au plateau
    for(int i = nb_animaux/4; i < (nb_animaux/2); i++){
        x = random()%largeur_plateau;
        y = random()%longueur_plateau;
        while (!plateau_.estCaseVide(x,y))
        {
            x = random()%largeur_plateau;
            y = random()%longueur_plateau;
        }
        ours.push_back(new Ours(largeur_plateau, longueur_plateau, x, y));
    }
    for(Ours* o : ours){
    plateau_.ajouterAnimal(o);
    }

    //Ajout des loups au plateau
    for(int i = nb_animaux/2; i < (nb_animaux/2 + nb_animaux/4); i++){
        x = random()%largeur_plateau;
        y = random()%longueur_plateau;
        while (!plateau_.estCaseVide(x,y))
        {
            x = random()%largeur_plateau;
            y = random()%longueur_plateau;
        }
        loups.push_back(new Loup(largeur_plateau, longueur_plateau, x, y));
    }
    for(Loup* lo : loups){
    plateau_.ajouterAnimal(lo);
    }

    //Ajout des pierres au plateau
    for(int i = (nb_animaux/2 + nb_animaux/4); i < nb_animaux; i++){
        x = random()%largeur_plateau;
        y = random()%longueur_plateau;
        while (!plateau_.estCaseVide(x,y))
        {
            x = random()%largeur_plateau;
            y = random()%longueur_plateau;
        }
        pierres.push_back(new Pierre(largeur_plateau, longueur_plateau, x, y));
    }
    for(Pierre* p : pierres){
    plateau_.ajouterAnimal(p);
    }

    //Début du jeu
    cout << "Plateau initial" << endl;
    plateau_.affichePlateau();
        while (cont){
        for (Animal *a : plateau_.getAnimals()){
            
                compt ++;
                cout << "------------------------------------------------------------------------"<< endl;
                a->deplace(largeur_plateau,longueur_plateau);
                for (Animal *b : plateau_.getAnimals()){
                    if (a->getX() == b->getX() && a->getY() == b->getY()){
                        a->attaque(*b);
                    }
                }
                cout << "Partie " << compt << endl;
                plateau_.affichePlateau();
                plateau_.afficherNbAnimalEnVie();
                plateau_.afficheAnimals();
                cout << "Voulez-vous continuer la partie ? [y/n]" << endl;
                cin >> b ;
                if (b=='y'){
                    cont = true;
                }
                else{
                    cont = false;
                }   
            }
   
        }

}