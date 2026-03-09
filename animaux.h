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

        //Méthodes
        bool resoudreAttaque(Attaque &a) const;
        string getNomAttaque() const;

        
};

//Surcharge
ostream& operator<<(ostream &os, const attaque_e &a);

class Animal{
protected:
    string  nom_;
    int     x_;
    int     y_;
    bool    vivant_;
    Attaque type_attaque_;

public:
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);

    string  getNom() const;
    int     getX() const;
    int     getY() const;
    bool    getVivant() const;
    Attaque getAttaque() const;

    void    setNom(string nom);
    void    setVivant(bool v);
    bool    attaque(Animal &a);

    virtual void setAttaque(Attaque atq) = 0;
    virtual void deplace(int maxX, int maxY) = 0;
};

class Lion : public Animal{

};

class Ours : public Animal{

};

class Pierre : public Animal{

};

class Loup : public Animal{

};

#endif