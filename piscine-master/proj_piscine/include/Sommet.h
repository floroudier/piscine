#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <string>
#include <fstream>
<<<<<<< HEAD
=======
#include "Svgfile.h"


>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d


class Sommet
{
public:
<<<<<<< HEAD
    Sommet();
=======
    Sommet(int i);
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);
<<<<<<< HEAD
    std::string GetName();
    int GetX();
    int GetY();
    int GetIndice();
    float GetCentralDegre();
    float GetCentralDegreNormal();
    void SetCentralDegre(float valeur);
    void SetCentralDegreNormal(float valeur);



protected:
=======
    void SetIndice(int indice);
    std::string getName();
    int getX();
    int getY();
    int getIndice();
    void afficherSVG(Svgfile *svgout);

>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d

private:
    int m_indice;
    std::string m_name;
    int m_x;
    int m_y;
<<<<<<< HEAD
    float m_centralDegre;
    float m_centralDegreNormal;
    int m_cvp;
=======
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d

};

#endif // SOMMET_H
