#include "Arete.h"

<<<<<<< HEAD
Arete::Arete()
{
    //ctor
}

Sommet*Arete::GetSommet1()
=======
Arete::Arete(int i) // Constructeur
{
    m_num=i;
}

Sommet* Arete::GetSommet1() // Accesseurs
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    {
        return m_sommet1;
    }

<<<<<<< HEAD
Sommet*Arete::GetSommet2()
=======
Sommet* Arete::GetSommet2()
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
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

<<<<<<< HEAD
=======

void Arete::SetSommet1(Sommet* nouveau) // Setteurs afin de modifier les valeurs des attributs
//Type a changer si besoin de plus d'informations sur le sommet
{

    m_sommet1=nouveau;
}

void Arete::SetSommet2(Sommet* nouveau)
{
    m_sommet2=nouveau;
}

void Arete::SetNum(int numero)
{
    m_num=numero;
}

void Arete::SetPoids(double poids)
{
    m_poids=poids;
}

int Arete::GetIndice1()
{
    return m_sommet1->getIndice();
}

int Arete::GetIndice2()
{
    return m_sommet2->getIndice();
}

int Arete::GetXSommet1()
{
    return m_sommet1->getX();
}

int Arete::GetYSommet1()
{
    return m_sommet1->getY();
}

int Arete::GetXSommet2()
{
    return m_sommet2->getX();
}

int Arete::GetYSommet2()
{
    return m_sommet2->getY();

}


void Arete::afficherSVGarete(Svgfile *svgout)
{
    svgout->addLine(GetXSommet1()*100,GetYSommet1()*100,GetXSommet2()*100,GetYSommet2()*100);

}
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
Arete::~Arete()
{
    //dtor
}
