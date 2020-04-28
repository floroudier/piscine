#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <string>
#include <fstream>


class Sommet
{
public:
    Sommet();
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);
    std::string GetName();
    int GetX();
    int GetY();
    int GetIndice();
    float GetCentralDegre();
    float GetCentralDegreNormal();
    void SetCentralDegre(float valeur);
    void SetCentralDegreNormal(float valeur);



protected:

private:
    int m_indice;
    std::string m_name;
    int m_x;
    int m_y;
    float m_centralDegre;
    float m_centralDegreNormal;
    int m_cvp;

};

#endif // SOMMET_H
