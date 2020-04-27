#ifndef GRAPHE_H
#define GRAPHE_H
#include <Sommet.h>
#include <vector>
#include <Arete.h>
#include <string>



class Graphe
{
public:
    Graphe(std::string fichier);
    Graphe(std::string fichier, std::string fichierPonderation);
    void afficher();
    void afficherPondere();


protected:

private:
    int m_orientation;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
    std::vector <Arete*> m_arete;
};

#endif // GRAPHE_H
