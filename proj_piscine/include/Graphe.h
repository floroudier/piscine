#ifndef GRAPHE_H
#define GRAPHE_H


class Graphe
{
public:
    Graphe();
    virtual ~Graphe();

protected:

private:
    bool m_orient;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
};

#endif // GRAPHE_H
