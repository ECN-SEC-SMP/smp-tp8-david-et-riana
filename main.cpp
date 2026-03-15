#include <cassert>
#include <iostream>
#include <stdlib.h>
#include "animaux.h"
#include "plateau.h"
#include "jeu.h"

using namespace std;

int main() {
    srand(time(NULL));

// Test des attaques
    Attaque a1 = Attaque();
    Attaque a2 = Attaque(2);
    Attaque a3 = Attaque(1);
    Attaque a4 = Attaque(0);
    Attaque a5 = Attaque(2);

    cout << "-------TEST ATTAQUE RANDOM ET PRÉVUE-------" << endl;
    cout << "Attaque random :" << endl;
    cout << a1.getTypeAttaque() << endl;
    cout << "Attaque prévue :" << endl;
    cout << a2.getTypeAttaque() << endl;
    cout << "-------------------------------------------" << endl;

    cout << "-------TEST RESOLUTION ATTAQUE-------" << endl;
    cout << "Attaque gagnante pour a2 :" << endl;
    cout << a2.resoudreAttaque(a3) << endl;
    cout << "Attaque perdante pour a2 :" << endl;
    cout << a2.resoudreAttaque(a4) << endl;
    cout << "Attaque avec égalité :" << endl;
    cout << a2.resoudreAttaque(a5) << endl;
    cout << "-------------------------------------------" << endl;

    // Test plateau
    const int maxX = 5;
    const int maxY = 6;
    auto p = Plateau(maxX,maxY);

    // Affichage du plateau vide
    p.affichePlateau();

    p.ajouterAnimal(new Loup(maxX, maxY, 1, 1));
    p.ajouterAnimal(new Lion(maxX, maxY, 2, 2));
    p.ajouterAnimal(new Ours(maxX, maxY, 3, 4));
    p.ajouterAnimal(new Pierre(maxX, maxY, 2, 3));

    p.ajouterAnimal(new Pierre(maxX, maxY, 5, 6));
    assert(p.getAnimalAtIndex(4)->getX() == 0 && "Position x réelle de la pierre doit être 0");
    assert(p.getAnimalAtIndex(4)->getY() == 0 && "Position y réelle de la pierre doit être 0");

    p.getAnimalAtIndex(3)->setX(6);
    assert(p.getAnimalAtIndex(3)->getX() == 1 && "Position x réelle de la pierre doit être 1");

    p.getAnimalAtIndex(1)->setY(6);
    assert(p.getAnimalAtIndex(1)->getY() == 0 && "Position y réelle du lion doit être 0");

    // Affichage du plateau avec un Loup, un Lion, un Ours et une Pierre
    cout << "-------Plateau : Loup, Lion, Ours et Pierre -------" << endl;
    p.affichePlateau();
    p.afficherNbAnimalEnVie();

    p.afficheAnimals();

    // Test attaque
    cout << "-------Test attaque --------" << endl;
    auto lion2   = Lion(maxX, maxY);
    auto loup2   = Loup(maxX, maxY);
    auto loup3   = Loup(maxX, maxY);
    auto loup4   = Loup(maxX, maxY);
    auto ours2   = Ours(maxX, maxY);
    auto ours3   = Ours(maxX, maxY);
    auto pierre3 = Pierre(maxX, maxY);
    auto pierre4 = Pierre(maxX, maxY);

    // ----------------------------------------------------------------------------------

    auto attq_feuille_pierre = lion2.attaque(pierre3);
    assert(attq_feuille_pierre == true && "La feuille gagne contre la pierre");
    assert(lion2.getVivant() == true && "Le lion doit être vivant après l'attaque");
    assert(pierre3.getVivant() == false && "La pierre doit être morte après l'attaque");

    auto attq_ciseaux_pierre = loup2.attaque(pierre4);
    assert(attq_ciseaux_pierre == false && "Les ciseaux perdent contre la pierre");
    assert(loup2.getVivant() == false && "Le loup doit être mort après l'attaque");
    assert(pierre4.getVivant() == true && "La pierre doit être vivante après l'attaque");

    // ----------------------------------------------------------------------------------

    auto attq_pierre_ciseaux = pierre4.attaque(loup3);
    assert(attq_pierre_ciseaux == true && "La pierre gagne contre les ciseaux");
    assert(pierre4.getVivant() == true && "La pierre doit être vivante après l'attaque");
    assert(loup3.getVivant() == false && "Le loup doit être mort après l'attaque");

    auto attq_feuille_ciseaux = ours2.attaque(loup4);
    assert(attq_feuille_ciseaux == false && "La feuille perd contre les ciseaux");
    assert(ours2.getVivant() == false && "L'ours doit être mort après l'attaque");
    assert(loup4.getVivant() == true && "Le loup doit être vivant après l'attaque");

    // ----------------------------------------------------------------------------------

    auto attq_pierre_feuille = pierre4.attaque(ours3);
    assert(attq_pierre_feuille == false && "La pierre perd contre la feuille");
    assert(pierre4.getVivant() == false && "La pierre doit être morte après l'attaque");
    assert(ours3.getVivant() == true && "L'ours doit être vivant après l'attaque");

    auto attq_ciseaux_feuille = loup4.attaque(ours3);
    assert(attq_ciseaux_feuille == true && "Les ciseaux gagnent contre la feuille");
    assert(loup4.getVivant() == true && "Le loup doit être vivant après l'attaque");
    assert(ours3.getVivant() == false && "L'ours doit être mort après l'attaque");

    // ----------------------------------------------------------------------------------
    // Attaque un animal vivant vs en animal mort

    auto attq_vivant_mort = loup4.attaque(ours3);
    assert(attq_vivant_mort == false && "Un animal vivant ne peut pas attaquer un animal mort");
    assert(loup4.getVivant() == true && "Le loup doit être vivant après l'attaque");
    assert(ours3.getVivant() == false && "L'ours doit être mort après l'attaque");

    auto attq_mort_vivant = ours3.attaque(loup4);
    assert(attq_mort_vivant == false && "Un animal mort ne peut pas attaquer un animal vivant");
    assert(ours3.getVivant() == false && "L'ours doit être mort après l'attaque");
    assert(loup4.getVivant() == true && "Le loup doit être vivant après l'attaque");

    auto attq_mort_mort = pierre4.attaque(ours3);
    assert(attq_mort_mort == false && "Un animal mort ne peut pas attaquer un animal mort");
    assert(pierre4.getVivant() == false && "La pierre doit être morte après l'attaque");
    assert(ours3.getVivant() == false && "L'ours doit être mort après l'attaque");

    cout << "------------------------------------------------------------------------"<< endl;
    int longu;
    int larg;

    cout << "Quelle est la largeur de plateau souhaitée ?" << endl;
    cin >> larg ;
    cout << "Quelle est la longueur de plateau souhaitée ?" << endl;
    cin >> longu ;
    Plateau pl(larg,longu);
    Loup* loup1   = new Loup(larg, longu, 1, 1);  // x=1, y=1
    Lion* lion1   = new Lion(larg, longu, 2, 2);
    Ours* ours1   = new Ours(larg, longu, 3, 4);
    Pierre* pierre1 = new Pierre(larg, longu, 0, 0);
    pl.ajouterAnimal(loup1);
    pl.ajouterAnimal(lion1);
    pl.ajouterAnimal(ours1);
    pl.ajouterAnimal(pierre1);
    pl.afficheAnimals();
    Jeu j(pl);
    j.partie(larg,longu);

    return 0;
}