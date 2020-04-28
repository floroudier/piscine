#ifndef GRAPHE_H
#define GRAPHE_H
#include <Sommet.h>
#include <vector>
#include <Arete.h>
#include <string>
#include "Svgfile.h"


class Graphe
{
public:
    Graphe(std::string fichier); //Constructeur
    Graphe(std::string fichier, std::string fichierPonderation); //Constructeur surchargé afin de charger pondération
    void afficher();
    void afficherPondere();
    void afficherGraphSVG(Svgfile*svgout);
    void centralDegre();
    void centralVecProp();


protected:

private:
    int m_orientation;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
    std::vector <Arete*> m_arete;
};

#endif // GRAPHE_H

