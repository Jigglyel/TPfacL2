#include<iostream>
#include<string>
#include<array>
#include<cmath>



struct maillon
{
    float val;
    maillon* suiv;
};
using pile=maillon*;

struct tab
{
    std::array<std::string,100>tab;
    int taille;
};
float dépiler(pile &P)
{
    maillon*tier;
    float tierval;
    tier=P->suiv;
    tierval=P->val;
    delete P;
    P=tier;
    return tierval;
}

void empiler(pile &P, float val)
{
    maillon*tier=P;
    P=new maillon;
    P->val=val;
    P->suiv=tier;
}


void saisie(tab&T)
{
    std::string val="lol";
    int i=0;
    while (val!="")
    {
        std::cout<<"veuillez entrer votre opérateur ou nombre :";
        std::getline(std::cin,val);
        if (val!="")
        {
                T.tab[i]=val;
                T.taille++;
                ++i;
        }
    }
    
}
float puissance(float val, float puiss)
{
    if (puiss==0)
    {
        return 1;
    }
    else return val*puissance(val,puiss-1);
    
}
float évaluation(tab T)
{
    pile P;
    float aux;
    for (int i = 0; i < T.taille; i++)
    {
        if (T.tab[i]=="+")
        {   aux=dépiler(P);
            empiler(P,dépiler(P)+aux);
        }
        else
        if (T.tab[i]=="-")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)-aux);
        }
        else
        if (T.tab[i]=="/")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)/aux);
        }
        else
        if (T.tab[i]=="*")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)*aux);
        }
        if (T.tab[i]=="^")
        {
            aux=dépiler(P);
            empiler(P,puissance(dépiler(P),aux));
        }
        if (T.tab[i]=="RAC")
        {
            empiler(P,std::sqrt(dépiler(P)));
        }

        else
            if (T.tab[i]=="PI")
            {
                empiler(P,3.14159);
            }
            else
            std::cout<<P->val<<std::endl;
                empiler(P,std::stof(T.tab[i])); 
    }
    return dépiler(P);
}


int main()
{
    tab T;
    saisie(T);
    std::cout<<"l'évaluation de la formule est : "<<évaluation(T)<<std::endl;
}
