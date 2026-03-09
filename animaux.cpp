/*TODO :
- expliquer pourquoi avoir choisi d'implémenter un enum
- expliquer pourquoi avoir ajouter une classe plateau*/

#include <iostream>
#include "animaux.h"

using namespace std;

// Méthodes de la classe Attaque

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

string Attaque::getNomAttaque() const{

}

// Surcharge de l'opérateur <<

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

/**
 * La pierre ne se déplace pas
 * @param maxX Taille maximale de l'aire de jeu en x
 * @param maxY Taille maximale de l'aire de jeu en y
 */
void Pierre::deplace(int maxX, int maxY) {
    // La pierre ne se déplace pas
}

/**
 * La pierre attaque toujours pierre
 * @param atq Attaque à effectuer
 */
void Pierre::setAttaque(Attaque atq) {
    // La pierre attaque toujours pierre
}

/**
 * Le loup se déplace de manière aléatoire sur le plateau de jeu
 * x vaut une valeur aléatoire entre 0 et maxX - 1
 * y vaut une valeur aléatoire entre 0 et maxY - 1
 * @param maxX Taille maximale de l'aire de jeu en x
 * @param maxY Taille maximale de l'aire de jeu en y
 */
void Loup::deplace (int maxX, int maxY) {
    x_ = random()%maxX;
    y_ = random()%maxY;
}

void Loup::setAttaque(Attaque atq) {
    type_attaque_ = atq;
}

string Loup::getChar() const {
    return "🐺";
}

string Pierre::getChar() const {
    return  "🗿";
}

string Lion::getChar() const {
    return "🦁";
}

string Ours::getChar() const {
    return "🐻";
}

/**
 * Le lion se déplace de manière aléatoire sur le plateau de jeu
 * x et y sont modifiés de -1 ou 1
 * TODO: Assurer que la nouvelle position du lion est bien dans les limites du plateau de jeu
 * @param maxX Taille maximale de l'aire de jeu en x
 * @param maxY Taille maximale de l'aire de jeu en y
 */
void Lion::deplace(int maxX, int maxY) {
    int positions_possibles[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int random_index = random()%4;

    x_ += positions_possibles[random_index][0];
    y_ += positions_possibles[random_index][1];
}