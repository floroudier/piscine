#include "Graphe.h"

<<<<<<< HEAD
Graphe::Graphe(std::string fichier)
{
    std::ifstream ifs{fichier};
=======

Graphe::Graphe(std::string fichier)
{
    std::ifstream ifs{fichier}; // Chargement du fichier en fonction du nom de ce dernier
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );
    ifs >> m_orientation;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture orientation du graphe");
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    for (int i=0; i<m_ordre; ++i)
<<<<<<< HEAD
        m_sommets.push_back( new Sommet[i] );
    std::string name;
    int x,y,indice;
    for(int j=0; j<m_ordre; ++j)
    {
        ifs>>indice;
        ifs>>name >> x>> y ;
        // Utilisation c??
        m_sommets [j] ->GetX(), m_sommets[j]->GetY();
=======
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
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
<<<<<<< HEAD
    int num1,num2;
    for (int k=0; k<m_taille; ++k)
    {
        ifs>>num1>>num2;
        m_arete[k] ->GetSommet1(), m_arete[k]->GetSommet2();
=======

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

>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/
<<<<<<< HEAD
    }
}

/*Graphe::Graphe(std::string fichier, std::string fichierPonderation)
{
    std::ifstream ifs{fichier};
=======

    }

}

Graphe::Graphe(std::string fichier,std::string fichierPonderation)// Chargement si arbre pondéré
{
    std::ifstream ifs{fichier};
    std::ifstream ifs2 {fichierPonderation};
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );
    ifs >> m_orientation;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture orientation du graphe");
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    for (int i=0; i<m_ordre; ++i)
<<<<<<< HEAD
        m_sommets.push_back( new Sommet[i] );
    std::string name;
    int a,b;
    for(int i=0; i<m_ordre; ++i)
    {
        ifs>>name >> a >> b ;
        // Utilisation c??
        m_sommets [i] ->GetX(), m_sommets[i]->GetY();
=======
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
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
<<<<<<< HEAD
    int num1,num2;
    for (int i=0; i<m_taille; ++i)
    {
        ifs>>num1>>num2;
        m_arete[i] ->GetSommet1(), m_arete[i]->GetSommet2();
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);
    }
}*/

svgfile svgout;
svgout.addGrid();

void Graphe::centralDegre()         /** Fonction de centralité de degré **/
{
    for(i=0, i<m_taille, i++)           /** Parcourir les aretes **/
    {
        m_arete [i]->GetSommet1()->SetDegre(m_arete [i]->GetSommet1()->GetDegre()+1);           /** Ajouter 1 au degré pour chaque arete qui passe par ce sommet **/
        if(m_orientation==0)
            m_arete [i]->GetSommet2()->SetDegre(m_arete [i]->GetSommet2()->GetDegre()+1);       /** Si le graphe n'est pas orienté, les aretes vont dans les deux sens **/
        m_sommets[i]->SetCentralDegreNormal(m_sommets[i]->GetCentralDegre()/(m_ordre-1));       /** Calcul de la centralité de degré normalisée **/
    }
}



=======

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
>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d




<<<<<<< HEAD

void Graphe::centralVecProp()       /** Fonction de centralité de vecteur propre **/
{
    double lambda=0;
    double lambdaTemp=0;                                                    /** valeur temporaire pour comparer lambda avec celui de la boucle précédente **/
        for(i=0, i<m_ordre, i++)                                            /** Parcourir les sommets **/
            m_sommet[i]->Setcvp(m_sommet[i]->GetCentralDegre());            /** initialisation du CVP avec le nombre de degré de chaque sommet **/
    do                                                                      /** boucle tant que lambda varie trop**/
    {
        for(i=0, i<m_ordre,i++)                                             /** Parcourir les sommets **/
        {
            int c[i]=0;                                                     /** Remise à zero du C **/
            int ctot=0;                                                     /** somme totale des C **/
            for(j=0, j<m_taille,j++)                                        /** Parcourir les aretes **/
            {
                if(m_arete[j]->sommet1==m_sommet[i])                        /** Si l'arete part du sommet étudié **/
                {
                    c[i]=c[i]+m_arete[j]->GetSommet2->GetCvp();             /** Ajouter le cvp du descendant au C du prédecesseur **/
                }
            }
            for(i=0, i<m_ordre, i++)                                        /** Boucle de clacul du Ctot **/
            {
                ctot= ctot+c[i];
            }
            lambdaTemp=lambda;
            lambda= /*jsp*/                                                 /** Calcul du lambda **/
                for(i=0, i<m_ordre, i++)                                    /** Boucle de calcul du Cvp de chaque sommet **/
            {
                cvp[i]=c[i]/lambda;
            }
        }
    }
   /* while (lambda/lambdaTemp<=1,5); */                                    /** Tant que lambda varie trop **/
   while (lambda-lambdaTemp>=0.1);
}
=======
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





>>>>>>> bcb0e151d81297de2ea14080a105a97a0bb0727d
