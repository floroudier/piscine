#include "Implementation.h"
#include <string>


std::string choixFichier ()
{
    std::string fichier;
    std::cout<<"Entrez nom du fichier de topologie"<<std::endl;
    std::cin>>fichier;
    return fichier;
}

std::string choixFichierPond()
{
    std::string fichierPondere;
    std::cout<<std::endl<<"Entrez nom du fichier de ponderations"<<std::endl;
    std::cin>>fichierPondere;
    return fichierPondere;
}


void menu ()
{
    int choixPondere;
    std::cout<<"Votre arbre est-il pondere?"<<std::endl;
    //Svgfile svgout;
    //svgout.addGrid();
    do
    {
        std::cout<<"0 : Oui"<<std::endl<<"1 : Non"<<std::endl;
        std::cin>>choixPondere;

    }while(choixPondere!=0 && choixPondere !=1);

    if(choixPondere==1)
    {
        std::string nomFichier;
        nomFichier=choixFichier();

        Graphe objet (nomFichier);

        objet.afficher();


    }

    if (choixPondere==0)
    {
        std::string nomFichier;
        std::string nomFichierPonderation;

        nomFichier=choixFichier();
        nomFichierPonderation=choixFichierPond();


        Graphe objetPondere (nomFichier,nomFichierPonderation);

        objetPondere.afficherPondere();

    }
}
