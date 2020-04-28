#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include "fstream"


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

protected:

private:
    std::string m_name;
    int m_x;
    int m_y;

};

#endif // SOMMET_H
