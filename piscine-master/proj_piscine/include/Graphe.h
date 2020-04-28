#ifndef GRAPHE_H
#define GRAPHE_H
#include <Sommet.h>
#include <vector>
#include <Arete.h>
<<<<<<< HEAD
=======
#include <string>
#include "Svgfile.h"

>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d

class Graphe
{
public:
<<<<<<< HEAD
    Graphe(std::string fichier);
    Graphe(std::string fichier, std::string fichierPonderation);
=======
    Graphe(std::string fichier); //Constructeur
    Graphe(std::string fichier, std::string fichierPonderation); //Constructeur surchargé afin de charger pondération
    void afficher();
    void afficherPondere();
    void afficherGraphSVG(Svgfile*svgout);
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d


protected:

private:
    int m_orientation;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
    std::vector <Arete*> m_arete;
};

#endif // GRAPHE_H
