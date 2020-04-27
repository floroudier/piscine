#ifndef SOMMET_H
#define SOMMET_H


class Sommet
{
public:
    Sommet();
    virtual ~Sommet();
    void SetName(std::string name);
    void SetX(int x);
    void SetY(int y);

    std::string Sommet::GetName()
    {
        return m_name;
    }

    int Sommet:GetX()
    {
        return m_x;
    }

    int Sommet:GetY()
    {
        return m_y;
    }
protected:

private:
    std::string m_name;
    int m_x;
    int m_y;

};

#endif // SOMMET_H
