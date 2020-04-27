#include "Arete.h"

Arete::Arete()
{
    //ctor
}

Sommet*Arete::GetSommet1()
    {
        return m_sommet1;
    }

Sommet*Arete::GetSommet2()
    {
        return m_sommet2;
    }

int Arete::GetNum()
    {
        return m_num;
    }

double Arete::GetPoids()
    {
        return m_poids;
    }

Arete::~Arete()
{
    //dtor
}
