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
        m_sommets.push_back( new Sommet{i} );
    std::string name;
    int x,y,indice;
    for(int j=0; j<m_ordre; ++j)
    {
        ifs>>indice;
        m_sommets[j]->SetIndice(indice);
        ifs>>name;
        m_sommets[j]->SetName(name);
        ifs>>x>> y ;
        m_sommets [j] ->SetX(x), m_sommets[j]->SetY(y);
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    for (int t=0; t<m_taille; ++t)
    m_arete.push_back( new Arete{t} );
    int num1,num2,numeroArete;
    for (int k=0; k<m_taille; ++k)
    {
        ifs>>numeroArete;
        m_arete[k]->SetNum(numeroArete);
        ifs>>num1>>num2;
        m_arete[k] ->SetSommet1(num1), m_arete[k]->SetSommet2(num2);
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/

    }

}

Graphe::Graphe(std::string fichier,std::string fichierPonderation)
{
    std::ifstream ifs{fichier};
    std::ifstream ifs2 {fichierPonderation};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );
    ifs >> m_orientation;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture orientation du graphe");
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    for (int i=0; i<m_ordre; ++i)
        m_sommets.push_back( new Sommet{i} );
    std::string name;
    int x,y,indice;
    for(int j=0; j<m_ordre; ++j)
    {
        ifs>>indice;
        m_sommets[j]->SetIndice(indice);
        ifs>>name;
        m_sommets[j]->SetName(name);
        ifs>>x>> y ;
        m_sommets [j] ->SetX(x), m_sommets[j]->SetY(y);
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    for (int t=0; t<m_taille; ++t)
    m_arete.push_back( new Arete{t} );
    int num1,num2,numeroArete;
    for (int k=0; k<m_taille; ++k)
    {
        ifs>>numeroArete;
        m_arete[k]->SetNum(numeroArete);
        ifs>>num1>>num2;
        m_arete[k] ->SetSommet1(num1), m_arete[k]->SetSommet2(num2);
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/

    }

    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture le deuxieme fichier " + fichierPonderation );
    ifs2>>m_taille;
    int poids;
    for(int z=0;z<m_taille;++z)
    {
        ifs2>>poids;
        m_arete[z]->SetPoids(poids);
            if ( ifs2.fail() )
            throw std::runtime_error("Probleme lecture poids");
    }


}

void Graphe::afficher()
{

    std::cout<<"Orientation : "<<m_orientation<<std::endl;
    std::cout<<"Ordre : "<<m_ordre<<std::endl;
    for(int i=0;i<m_ordre;++i)
    {
        std::cout<<m_sommets[i]->getIndice();
        std::cout<<m_sommets[i]->getName();
        std::cout<<m_sommets[i]->getX();
        std::cout<<m_sommets[i]->getY()<<std::endl;
    }
    std::cout<<"Taille : "<<m_taille<<std::endl;
    for(int j=0;j<m_taille;++j)
    {
        std::cout<<m_arete[j]->GetNum();
        std::cout<<m_arete[j]->GetSommet1();
        std::cout<<m_arete[j]->GetSommet2()<<std::endl;
    }


}

void Graphe::afficherPondere()
{

    std::cout<<"Orientation : "<<m_orientation<<std::endl;
    std::cout<<"Ordre : "<<m_ordre<<std::endl;
    for(int i=0;i<m_ordre;++i)
    {
        std::cout<<m_sommets[i]->getIndice()<<" ";
        std::cout<<m_sommets[i]->getName()<<" ";
        std::cout<<m_sommets[i]->getX()<<" ";
        std::cout<<m_sommets[i]->getY()<<std::endl;
    }
    std::cout<<"Taille : "<<m_taille<<std::endl;
    for(int j=0;j<m_taille;++j)
    {
        std::cout<<m_arete[j]->GetNum()<<" ";
        std::cout<<m_arete[j]->GetSommet1()<<" ";
        std::cout<<m_arete[j]->GetSommet2()<<"   ";
        std::cout<<"Poids : "<<m_arete[j]->GetPoids()<<std::endl;
    }





}




