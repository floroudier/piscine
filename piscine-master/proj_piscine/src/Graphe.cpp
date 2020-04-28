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
    int x,y,indice;
    for(int j=0; j<m_ordre; ++j)
    {
        ifs>>indice;
        ifs>>name >> x>> y ;
        // Utilisation c??
        m_sommets [j] ->GetX(), m_sommets[j]->GetY();
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int num1,num2;
    for (int k=0; k<m_taille; ++k)
    {
        ifs>>num1>>num2;
        m_arete[k] ->GetSommet1(), m_arete[k]->GetSommet2();
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        /*m_sommets[num1]->ajouterSucc(m_sommets[num2]);
        //si le graphe n'est pas orienté
        //si num2 est successeur de num1, num1 est successeur de num2
        if(!m_orientation)
            m_sommets[num2]->ajouterSucc(m_sommets[num1]);*/
    }
}

/*Graphe::Graphe(std::string fichier, std::string fichierPonderation)
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
        ifs>>name >> a >> b ;
        // Utilisation c??
        m_sommets [i] ->GetX(), m_sommets[i]->GetY();
    }
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
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
