#include "Graphe.h"


Graphe::Graphe(std::string fichier)
{
    std::ifstream ifs{fichier}; // Chargement du fichier en fonction du nom de ce dernier
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
    for(int j=0; j<m_ordre; ++j) // Remplissage du tableau de sommets
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
    int numeroArete;
    int sommet1;
    int sommet2;
    for (int k=0; k<m_taille; ++k) // Remplissage du tableau d'aretes
    {
        ifs>>numeroArete;
        m_arete[k]->SetNum(numeroArete);
        ifs>>sommet1>>sommet2;
        for(unsigned int i=0;i<m_sommets.size();++i)
        {
            if(m_sommets[i]->getIndice()==sommet1)
            {
                m_arete[k]->SetSommet1(m_sommets[i]);
            }

            if(m_sommets[i]->getIndice()==sommet2)
            {
                m_arete[k]->SetSommet2(m_sommets[i]);
            }

        }

        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/

    }

}

Graphe::Graphe(std::string fichier,std::string fichierPonderation)// Chargement si arbre pondéré
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
    int numeroArete;
    int sommet1;
    int sommet2;
    for (int k=0; k<m_taille; ++k)
    {
        ifs>>numeroArete;
        m_arete[k]->SetNum(numeroArete);
        ifs>>sommet1>>sommet2;
        for(unsigned int i=0;i<m_sommets.size();++i)
        {
            if(m_sommets[i]->getIndice()==sommet1)
            {
                m_arete[k]->SetSommet1(m_sommets[i]);
            }

            if(m_sommets[i]->getIndice()==sommet2)
            {
                m_arete[k]->SetSommet2(m_sommets[i]);
            }

        }

        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
       /* m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/

    }

    if (!ifs2) // Recupération des informations du fichier des pondérations afin de les mettre dans le tableau d'aretes
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

void Graphe::afficher() // Affichage en console du fichier de topologie
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
        std::cout<<m_arete[j]->GetIndice1()<<" ";
        std::cout<<m_arete[j]->GetIndice2()<<std::endl;
    }


}

void Graphe::afficherPondere()// Affichage en console des fichiers de topologie et de pondération
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
        std::cout<<m_arete[j]->GetIndice1()<<" ";
        std::cout<<m_arete[j]->GetIndice2()<<"   ";
        std::cout<<"Poids : "<<m_arete[j]->GetPoids()<<std::endl;
    }




}

void Graphe::afficherGraphSVG(Svgfile*svgout)// Affichage des sommets en SVG
{
    for(unsigned int i=0;i<m_sommets.size();i++)
    {
        m_sommets[i]->afficherSVG(svgout);
    }
    for(unsigned int i=0;i<m_arete.size();i++)
    {
        m_arete[i]->afficherSVGarete(svgout);
    }
}





