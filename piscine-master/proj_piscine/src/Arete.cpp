#include "Arete.h"

Arete::Arete(int i)
{
    m_num=i;
}

int Arete::GetSommet1()
    {
        return m_sommet1;
    }

int Arete::GetSommet2()
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


void Arete::SetSommet1(int sommet1) //Type a changer si besoin de plus d'informations sur le sommet
{
    m_sommet1=sommet1;
}

void Arete::SetSommet2(int sommet2)
{
    m_sommet2=sommet2;
}

void Arete::SetNum(int numero)
{
    m_num=numero;
}

void Arete::SetPoids(double poids)
{
    m_poids=poids;
}
Arete::~Arete()
{
    //dtor
}
