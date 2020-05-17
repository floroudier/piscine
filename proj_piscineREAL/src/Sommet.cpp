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

void Sommet::SetVisiteDijkstra(int i)
{
    m_VisiteDijkstra=i;
}

int Sommet::GetVisiteDijkstra()
{
    return m_VisiteDijkstra;
}

std::vector <double> Sommet::GetDistanceDijkstra()
{
    return m_distanceDijkstra;
}

void Sommet::SetDistanceDijkstra(double distanceMin, int j)
{
    m_distanceDijkstra[j]=distanceMin;
}

void Sommet::SetCentralProxInv(int j)
{
    m_centralProxInv=m_centralProxInv + m_distanceDijkstra[j];
}

double Sommet::GetCentralProxInv()
{
    return m_centralProxInv;
}

void Sommet::SetCentralProx(int ordre, double centralProxInv)
{
    m_centralProx= (ordre-1)/centralProxInv;
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
