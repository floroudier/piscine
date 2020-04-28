#include <iostream>
#include "Implementation.h"
#include "Graphe.h"


int main()
{
    std::string nomFichier;

    nomFichier=choixFichier();


    Graphe exemple(nomFichier);

    exemple.afficher();

    return 0;
}
