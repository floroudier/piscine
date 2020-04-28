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

std::string Sommet::GetName()//Accesseurs
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

int Sommet::GetIndice()
{
    return m_indice;
}

int Sommet::GetCvp()
{
    return m_cvp;
}

void Sommet::SetCvp(int cvp)
{
    m_cvp=cvp;
}

int Sommet::GetDegre()
{
    return m_degre;
}

void Sommet::SetDegre(int degre)
{
    m_degre=degre;
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

void Sommet::afficherSVG(Svgfile *svgout)// Affichage en SVG de chaque sommet
{
    svgout->addText(m_x*100,m_y*100+30,m_name);
    svgout->addDisk(m_x*100,m_y*100,10);
}

Sommet::~Sommet()
{
    //dtor
}
