#include "Graphe.h"


Graphe::Graphe(std::string fichier)
{
    std::ifstream ifs{fichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );
    ifs >> m_orientation;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture orientation du graphe");
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    for (int i=0; i<m_ordre; ++i)
        m_sommets.push_back( new Sommet[i] );
    std::string name;
    int a,b;
    for(int i=0; i<m_ordre; ++i)
    {
        ifs>>name >> a >> b;                ///utilisation de c?
        m_sommets [i] ->GetX(), m_sommets[i]->GetY();
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int num1,num2;
    for (int i=0; i<m_taille; ++i)
    {
        ifs>>num1>>num2;
        m_aretes[i] ->GetSommet1(), m_aretes[i] ->GetSommet2();
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
      /*  m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/
    }
}
