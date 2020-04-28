#include <iostream>
#include "Implementation.h"
#include "Graphe.h"


int main()
{
    std::string nomFichier;

    nomFichier=choixFichier();

    std::cout<<nomFichier;

    Graphe exemple(nomFichier);
    return 0;
}
