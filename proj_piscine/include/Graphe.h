#ifndef GRAPHE_H
#define GRAPHE_H
#include "vector"
#include <Sommet.h>
#include <arete.h>

class Graphe
{
public:
    Graphe(std::string fichier);
    ~Graphe();

protected:

private:
    bool m_orientation;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
    std::vector <Arete*> m_aretes;
};

#endif // GRAPHE_H
