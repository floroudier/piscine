#include "Sommet.h"

Sommet::Sommet(int i)
{
   m_indice=i;
}

void Sommet::SetName(std::string name)
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

std::string Sommet::getName()
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

Sommet::~Sommet()
{
    //dtor
}
