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

bool Attaque::resoudreAttaque(Attaque &a) const{
    if (getTypeAttaque() == attaque_e::pierre && a.getTypeAttaque() == attaque_e::ciseaux){
        return true;
    }
    else if (getTypeAttaque() == attaque_e::feuille && a.getTypeAttaque() == attaque_e::pierre){
        return true;
    }
    else if (getTypeAttaque() == attaque_e::ciseaux && a.getTypeAttaque() == attaque_e::feuille){
        return true;
    }
    else if (getTypeAttaque() == a.getTypeAttaque()){
        return (rand()%2);
    }
    else{
        return false;
    }
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

/**
 * Contructeur de la classe Animal
 * Place l'animal à la position (0, 0) sur le plateau de jeu
 * @param maxX Taille maximale de l'aire de jeu en x
 * @param maxY Taille maximale de l'aire de jeu en y
 */
Animal::Animal(int maxX, int maxY) {
    vivant_ = true;
    x_ = 0;
    y_ = 0;
}

/**
 * Contructeur de la classe Animal
 * Place l'animal à la position (a, b) sur le plateau de jeu
 * @param maxX Taille maximale de l'aire de jeu en x
 * @param maxY Taille maximale de l'aire de jeu en y
 * @param a Position en x de l'animal
 * @param b Position en y de l'animal
 */
Animal::Animal(int maxX, int maxY, int a, int b) {
    vivant_ = true;
    x_ = a;
    y_ = b;
}

string Animal::getNom() const {
    return nom_;
}

int Animal::getX() const {
    return x_;
}

int Animal::getY() const {
    return y_;
}

bool Animal::getVivant() const {
    return vivant_;
}

Attaque Animal::getAttaque() const {
    return type_attaque_;
}

void Animal::setNom(string nom) {
    nom_ = nom;
}

void Animal::setVivant(bool v) {
    vivant_ = v;
}
