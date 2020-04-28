#include "Sommet.h"

Sommet::Sommet()
{
    //ctor
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
Sommet::~Sommet()
{
    //dtor
}
