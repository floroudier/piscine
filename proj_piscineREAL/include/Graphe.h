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
    void Dijkstra();
    void centralProx();


protected:

private:
    int m_orientation;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
    std::vector <Arete*> m_arete;
    Sommet* sommetDepart;
    Sommet* sommetArrivee;
    Sommet* sommetVisite;
};

#endif // GRAPHE_H

