#ifndef ARETE_H
#define ARETE_H
#include <Sommet.h>

class Arete
{
public:
    Arete(int i);
    virtual ~Arete();
    int GetSommet1();
    int GetSommet2();
    void SetSommet1(int sommet1);
    void SetSommet2(int sommet2);
    void SetNum(int numero);
    int GetNum();
    double GetPoids();

protected:

private:
    int m_sommet1;
    int m_sommet2;
    double m_poids;
    int m_num;
};

#endif // ARETE_H
