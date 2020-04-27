#ifndef ARETE_H
#define ARETE_H


class Arete
{
public:
    Arete();
    virtual ~Arete();
    Sommet*Arete::GetSommet1()
    {
        return m_sommet1
    }

    Sommets*Arete::GetSommet2()
    {
        return m_sommet2;
    }

    int Arete::GetNum()
    {
        return m_num;
    }

    double Arete::GetPoids()
    {
        return m_poids;
    }

protected:

private:
    Sommet* m_sommet1;
    Sommet* m_sommet2;
    double m_poids;
    int m_num;
};

#endif // ARETE_H
