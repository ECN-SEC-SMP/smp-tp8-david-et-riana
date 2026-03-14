#ifndef SMP_TP8_DAVID_RIANA_ANIMAUX_H
#define SMP_TP8_DAVID_RIANA_ANIMAUX_H

#include <stdlib.h>
#include <iostream>

using namespace std;

enum class attaque_e {
    pierre  = 0,
    feuille = 1,
    ciseaux = 2
};

class Attaque{
        attaque_e attaque_ ;
    public :
        //Attaque aléatoire
        Attaque();
        //Attaque spécifique
        Attaque(int a);

        Attaque(attaque_e a);

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

    /**
     * x et y représentent la position de l'animal sur le plateau de jeu
     */
    int     x_;
    int     y_;
    bool    vivant_;
    int     maxX_;
    int     maxY_;
    Attaque type_attaque_;

public:
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);
    ~Animal() = default;

    int     getX() const;
    int     getY() const;
    void    setX(int x);
    void    setY(int y);
    bool    getVivant()  const;
    Attaque getAttaque() const;
    string  getNom()     const;

    void    setNom(string nom);
    void    setVivant(bool v);
    bool    attaque(Animal &a);

    virtual void setAttaque()                = 0;
    virtual void deplace(int maxX, int maxY) = 0;
    virtual string getChar()           const = 0;
};

ostream& operator<<(ostream &os, const Animal &a);

class Lion : public Animal{
public:
    static int id;

    Lion(const int maxX,  const int maxY) : Animal(maxX, maxY) {
        Lion::id++;
        nom_ = "Lion " + to_string(Lion::id);
    } ;
    Lion(const int maxX, const int maxY, const int a, const int b) : Animal(maxX, maxY, a, b) {
        Lion::id++;
        nom_ = "Lion " + to_string(Lion::id);
    };

    string getChar() const           override;
    void deplace(int maxX, int maxY) override;
    void setAttaque()                override;
};

class Ours : public Animal{
public:
    static int id;

    Ours(const int maxX, const int maxY)                           : Animal(maxX, maxY) {
        Ours::id++;
        nom_ = "Ours " + to_string(Ours::id);
    };
    Ours(const int maxX, const int maxY, const int a, const int b) : Animal(maxX, maxY, a, b) {
        Ours::id++;
        nom_ = "Ours " + to_string(Ours::id);
    };

    string getChar() const           override;

    void deplace(int maxX, int maxY) override;
    void setAttaque()                override;
};

class Pierre : public Animal{
public:
    static int id;

    Pierre(const int maxX, const int maxY)                           : Animal(maxX, maxY) {
        Pierre::id++;
        nom_ = "Pierre " + to_string(Pierre::id);
    };
    Pierre(const int maxX, const int maxY, const int a, const int b) : Animal(maxX, maxY, a, b) {
        Pierre::id++;
        nom_ = "Pierre " + to_string(Pierre::id);
    };

    void deplace(int maxX, int maxY) override;
    void setAttaque()                override;
    string getChar() const           override;
};

class Loup : public Animal{
public:
    static int id;

    Loup(const int maxX, const int maxY)                           : Animal(maxX, maxY) {
        Loup::id++;
        nom_ = "Loup " + to_string(Loup::id);
    };
    Loup(const int maxX, const int maxY, const int a, const int b) : Animal(maxX, maxY, a, b) {
        Loup::id++;
        nom_ = "Loup " + to_string(Loup::id);
    };

    void deplace(int maxX, int maxY) override;
    void setAttaque()                override;
    string getChar() const           override;
};

#endif