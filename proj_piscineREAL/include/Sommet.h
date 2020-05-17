#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <string>
#include <fstream>
#include "Svgfile.h"
#include <vector>




class Sommet
{
public:
    Sommet(int i);
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);
    void SetIndice(int indice);
    std::string GetName();
    int GetX();
    int GetY();
    int GetIndice();
    void afficherSVG(Svgfile *svgout);
    float GetCentralDegre();
    float GetCentralDegreNormal();
    void SetCentralDegre(float valeur);
    void SetCentralDegreNormal(float valeur);
    void SetDegre(int degre);
    int GetDegre();
    int GetCvp();
    void SetCvp(int cvp);
    void SetDistanceDijkstra(double distanceMin, int j);
    std::vector <double> GetDistanceDijkstra();
    void SetVisiteDijkstra(int i);
    int GetVisiteDijkstra();
    double GetCentralProxInv();
    void SetCentralProxInv(int j);
    void SetCentralProx(int ordre, double centralProxInv);

private:
    int m_indice;
    std::string m_name;
    int m_x;
    int m_y;
    float m_centralDegre;
    float m_centralDegreNormal;
    int m_cvp;
    int m_degre;
    std::vector <double> m_distanceDijkstra;
    int m_VisiteDijkstra;
    double m_centralProxInv;
    double m_centralProx;
};

#endif // SOMMET_H
