#include "Arete.h"

Arete::Arete(int i) // Constructeur
{
    m_num=i;
}

Sommet* Arete::GetSommet1() // Accesseurs
    {
        return m_sommet1;
    }

Sommet* Arete::GetSommet2()
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
    return m_sommet1->GetIndice();
}

int Arete::GetIndice2()
{
    return m_sommet2->GetIndice();
}

int Arete::GetXSommet1()
{
    return m_sommet1->GetX();
}

int Arete::GetYSommet1()
{
    return m_sommet1->GetY();
}

int Arete::GetXSommet2()
{
    return m_sommet2->GetX();
}

int Arete::GetYSommet2()
{
    return m_sommet2->GetY();

}


void Arete::afficherSVGarete(Svgfile *svgout)
{
    svgout->addLine(GetXSommet1()*100,GetYSommet1()*100,GetXSommet2()*100,GetYSommet2()*100);

}
Arete::~Arete()
{
    //dtor
}
