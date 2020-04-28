#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <string>
#include <fstream>
#include "Svgfile.h"




class Sommet
{
public:
    Sommet(int i);
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);
    void SetIndice(int indice);
    std::string getName();
    int getX();
    int getY();
    int getIndice();
    void afficherSVG(Svgfile *svgout);


private:
    int m_indice;
    std::string m_name;
    int m_x;
    int m_y;

};

#endif // SOMMET_H
