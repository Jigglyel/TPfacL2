#include <iostream>
#include<string>
#include<fstream>

struct arbretab{
    int taille;
    int indice;
    std::string* Tab;
    int *TabGauche,*TabDroit,*TabPere;
};


arbretab init(std::string ch)
{
    arbretab résultat;
    std::ifstream fic;
    int gauche,droit;
    fic.open(ch);
    if(fic.is_open())
    {
    
        fic>>résultat.taille;
        fic>>résultat.indice;
        résultat.TabDroit=new int[résultat.taille+1];
        résultat.TabGauche=new int[résultat.taille+1];
        résultat.TabPere=new int[résultat.taille+1];
        résultat.Tab=new std::string[résultat.taille+1];
        for (int i = 1; i <=résultat.taille; i++)
        {
            fic>>résultat.Tab[i];
            fic>>gauche;
            if(gauche!=0)
                résultat.TabPere[gauche]=i;
            résultat.TabGauche[i]=gauche;
            fic>>droit;
            if(droit!=0)
                résultat.TabPere[droit]=i;
            résultat.TabDroit[i]=droit;
            
        }
    }  
    else 
        std::cout<<"erreur d'ouverture du fichier "<<ch<<std::endl;
    return résultat;

}
void affiche(arbretab arbre)
{
    std::cout<<arbre.taille<<std::endl;
    std::cout<<arbre.indice<<std::endl;
    std::cout<<" ";
    for(int i=1;i<arbre.taille+1;++i)
    {
        std::cout<<arbre.Tab[i]<<" ";
    }
    std::cout<<std::endl<<" ";
    for(int i=1;i<arbre.taille+1;++i)
    {
        std::cout<<arbre.TabGauche[i];
    }
    std::cout<<std::endl<<" ";
    for(int i=1;i<arbre.taille+1;++i)
    {
        std::cout<<arbre.TabDroit[i];
    }
    std::cout<<std::endl<<" ";
    for(int i=1;i<arbre.taille+1;++i)
    {
        std::cout<<arbre.TabPere[i];
    }
    std::cout<<std::endl;
}
void affichage_Préfixe(arbretab arbre)
{
    std::cout<<arbre.Tab
    
}
int longueur(arbretab arbre, int indice)
{
    if (arbre.TabPere[indice]==0)
    {
        return 0;
    }
    else
        return 1+longueur(arbre,arbre.TabPere[indice]);
    
}
int main()
{
    arbretab arbre;
    arbre=init("./TP5.txt");
    affiche(arbre);
    std::cout<<longueur(arbre,1)<<std::endl;
}