#include "Sommet.h"

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
Sommet::~Sommet()
{
    //dtor
}
