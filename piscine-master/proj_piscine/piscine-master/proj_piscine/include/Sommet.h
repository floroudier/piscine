#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
<<<<<<< HEAD:proj_piscine/include/Sommet.h
#include "fstream"
=======
#include <string>
#include <fstream>
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d:piscine-master/proj_piscine/piscine-master/proj_piscine/include/Sommet.h


class Sommet
{
public:
    Sommet(int i);
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);
<<<<<<< HEAD:proj_piscine/include/Sommet.h
    std::string GetName();
    int GetX();
    int GetY();

=======
    void SetIndice(int indice);
    std::string getName();
    int getX();
    int getY();
    int getIndice();





>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d:piscine-master/proj_piscine/piscine-master/proj_piscine/include/Sommet.h
protected:

private:
    int m_indice;
    std::string m_name;
    int m_x;
    int m_y;

};

#endif // SOMMET_H
