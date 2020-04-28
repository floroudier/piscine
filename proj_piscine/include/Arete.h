#ifndef ARETE_H
#define ARETE_H
#include <Sommet.h>


class Arete
{
public:
    Arete();
    virtual ~Arete();
    Sommet*GetSommet1();
    Sommet*GetSommet2();
    int GetNum();
    double GetPoids();


protected:

private:
    Sommet* m_sommet1;
    Sommet* m_sommet2;
    double m_poids;
    int m_num;
};

#endif // ARETE_H
