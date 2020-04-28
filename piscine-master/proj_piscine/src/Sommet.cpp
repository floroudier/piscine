#include "Sommet.h"

Sommet::Sommet(int i)//Constructeur
{
   m_indice=i;
}

void Sommet::SetName(std::string name)// Setteurs
{
    m_name=name;
}
void Sommet::SetX(int x)
{
    m_x=x;
}
void Sommet::SetY(int y)
{
    m_y=y;
}
void Sommet::SetIndice(int indice)
{
    m_indice=indice;
}

std::string Sommet::getName()//Accesseurs
{
    return m_name;
}

int Sommet::getX()
{
    return m_x;
}

int Sommet::getY()
{
    return m_y;
}

int Sommet::getIndice()
{
    return m_indice;
}

void Sommet::afficherSVG(Svgfile *svgout)// Affichage en SVG de chaque sommet
{
    svgout->addText(m_x*100,m_y*100+30,m_name);
    svgout->addDisk(m_x*100,m_y*100,10);
}

Sommet::~Sommet()
{
    //dtor
}
