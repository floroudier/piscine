#include "Graphe.h"
#include <math.h>


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
            if(m_sommets[i]->GetIndice()==sommet1)
            {
                m_arete[k]->SetSommet1(m_sommets[i]);
            }

            if(m_sommets[i]->GetIndice()==sommet2)
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
            if(m_sommets[i]->GetIndice()==sommet1)
            {
                m_arete[k]->SetSommet1(m_sommets[i]);
            }

            if(m_sommets[i]->GetIndice()==sommet2)
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
        std::cout<<m_sommets[i]->GetIndice()<<" ";
        std::cout<<m_sommets[i]->GetName()<<" ";
        std::cout<<m_sommets[i]->GetX()<<" ";
        std::cout<<m_sommets[i]->GetY()<<std::endl;
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
        std::cout<<m_sommets[i]->GetIndice()<<" ";
        std::cout<<m_sommets[i]->GetName()<<" ";
        std::cout<<m_sommets[i]->GetX()<<" ";
        std::cout<<m_sommets[i]->GetY()<<std::endl;
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





void Graphe::centralDegre()         /** Fonction de centralité de degré **/
{
    int i=0;
    for(i=0; i<m_taille; i++)           /** Parcourir les aretes **/
    {
        m_arete [i]->GetSommet1()->SetDegre(m_arete [i]->GetSommet1()->GetDegre()+1);           /** Ajouter 1 au degré pour chaque arete qui passe par ce sommet **/
        if(m_orientation==0)
            m_arete [i]->GetSommet2()->SetDegre(m_arete [i]->GetSommet2()->GetDegre()+1);       /** Si le graphe n'est pas orienté, les aretes vont dans les deux sens **/
        m_sommets[i]->SetCentralDegreNormal(m_sommets[i]->GetCentralDegre()/(m_ordre-1));       /** Calcul de la centralité de degré normalisée **/
    }
}








void Graphe::centralVecProp()       /** Fonction de centralité de vecteur propre **/
{
    int i=0;
    int j=0;
    int c[i];                                                     /** Remise à zero du C **/
    int csi[i];
    int cvp[i];
    int ctot;
    double lambda=0;
    double lambdaTemp=0;                                                    /** valeur temporaire pour comparer lambda avec celui de la boucle précédente **/
        for(i=0; i<m_ordre; i++)                                            /** Parcourir les sommets **/
            m_sommets[i]->SetCvp(m_sommets[i]->GetCentralDegre());            /** initialisation du CVP avec le nombre de degré de chaque sommet **/
    do                                                                      /** boucle tant que lambda varie trop**/
    {
        for(i=0; i<m_ordre; i++)                                             /** Parcourir les sommets **/
        {
                                                             /** somme totale des C **/
            for(j=0; j<m_taille; j++)                                        /** Parcourir les aretes **/
            {
                if(m_arete[j]->GetSommet1()==m_sommets[i])                        /** Si l'arete part du sommet étudié **/
                {
                    c[i]=c[i]+m_arete[j]->GetSommet2()->GetCvp();             /** Ajouter le cvp du descendant au C du prédecesseur **/
                }
            }
            for(i=0; i<m_ordre; i++)                                        /** Boucle de clacul du Ctot **/
            {
                csi[i]=c[i]*c[i];
                ctot=ctot+csi[i];
            }
            lambdaTemp=lambda;
            lambda= sqrt(ctot);                                                 /** Calcul du lambda **/
                for(i=0; i<m_ordre; i++)                                    /** Boucle de calcul du Cvp de chaque sommet **/
            {
                cvp[i]=csi[i]/lambda;
            }
        }
    }
   /* while (lambda/lambdaTemp<=1,5); */                                    /** Tant que lambda varie trop **/
   while (lambda-lambdaTemp>=0.1);
   for(i=0; i<m_ordre; i++)
   {
       m_sommets[i]->SetCvp(cvp[i]);
   }
}

