#ifndef ARETE_H
#define ARETE_H
#include <Sommet.h>

class Arete
{
public:
    Arete(int i);
    ~Arete();
    Sommet* GetSommet1();
    Sommet* GetSommet2();
    int GetIndice1();
    int GetIndice2();
    int GetXSommet1();
    int GetYSommet1();
    int GetXSommet2();
    int GetYSommet2();
    int GetNum();
    double GetPoids();

    void SetSommet1(Sommet* nouveau);
    void SetSommet2(Sommet* nouveau);
    void SetNum(int numero);
    void SetPoids(double poids);

    void afficherSVGarete(Svgfile *svgout);

private:
    Sommet* m_sommet1; // Extremité 1 de l'arete
    Sommet* m_sommet2; // Extremité 2 de l'arete
    double m_poids;
    int m_num; // Numero de l'arete
};

#endif // ARETE_H
