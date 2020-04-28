#include "Sommet.h"

<<<<<<< HEAD
Sommet::Sommet()
{
    //ctor
}

int Sommet::GetIndice()
{
    return m_indice;
}

std::string Sommet::GetName()
{
    return m_name;
}

int Sommet::GetX()
{
    return m_x;
}

int Sommet::GetY()
{
    return m_y;
}

float Sommet::GetCentralDegre()
{
    return m_centralDegre;
}

float Sommet::GetCentralDegreNormal()
{
    return m_centralDegreNormal;
}

void Sommet::SetCentralDegre(float valeur)
{
    m_centralDegre=valeur;
}

void Sommet::SetCentralDegreNormal(float valeur)
{
    m_centralDegreNormal=valeur;
}
=======
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

>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
Sommet::~Sommet()
{
    //dtor
}
