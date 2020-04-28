#ifndef ARETE_H
#define ARETE_H
#include <Sommet.h>

class Arete
{
public:
<<<<<<< HEAD
    Arete();
    virtual ~Arete();
    Sommet* GetSommet1();
    Sommet* GetSommet2();
    int GetNum();
    double GetPoids();

protected:

private:
    Sommet* m_sommet1;
    Sommet* m_sommet2;
    double m_poids;
    int m_num;
=======
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

    void SetSommet1(Sommet* nouveau);
    void SetSommet2(Sommet* nouveau);
    void SetNum(int numero);
    void SetPoids(double poids);
    int GetNum();
    double GetPoids();
    void afficherSVGarete(Svgfile *svgout);

private:
    Sommet* m_sommet1; // Extremit� 1 de l'arete
    Sommet* m_sommet2; // Extremit� 2 de l'arete
    double m_poids;
    int m_num; // Numero de l'arete
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
};

#endif // ARETE_H
