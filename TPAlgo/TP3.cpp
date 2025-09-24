#include<iostream>
#include<string>
#include<array>
#include<cmath>
#include<cctype>



struct maillon
{
    float val;
    maillon* suiv;
};
using pile=maillon*;

struct tab
{
    std::array<std::string,100>tab;
    int taille=0;
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
bool isdigit(char c)
{
    return (c=='1' or c=='2' or c=='3' or c=='4' or c=='5' or c=='6' or c=='7' or c=='8' or c=='9' or c=='0' or c=='.');
}
bool isnumber(std::string phrase)
{
    for(long unsigned int i=0;i<phrase.length();++i)
        if(not isdigit(phrase[i]))
            return false;
    return true;
}
bool saisie2(tab&T)
{
    std::string expression;
    int j=0;
    std::cout<<"veuillez entrer votre formule :";
    std::getline(std::cin,expression);
    for(long unsigned int i=0;i<expression.length();++i)
    {
        if(expression[i]!=' ')
        {
            T.tab[j]+=expression[i];      
        }
        else
        {
            if(T.tab[j]!="PI" and T.tab[j]!="RAC" and T.tab[j]!="^" and T.tab[j]!="+" and T.tab[j]!="-" and T.tab[j]!="*" and T.tab[j]!="/")
                if(not isnumber(T.tab[j]))
                {
                    return false;
                }
            ++j;
            ++T.taille;
        }
    }
    if(T.tab[j]!="PI" and T.tab[j]!="RAC" and T.tab[j]!="^" and T.tab[j]!="+" and T.tab[j]!="-" and T.tab[j]!="*" and T.tab[j]!="/")
                if(not isnumber(T.tab[j]))
                {
                    std::cout<<"l'expression est incorrect ! "<<std::endl;
                    return false;
                }
    ++T.taille;
    return true;


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
    pile P=nullptr;
    int taille=0;
    float aux;
    for (int i = 0; i < T.taille; i++)
    {
        //std::cout<<T.tab[i]<<std::endl;
        if (T.tab[i]=="+")
        {   aux=dépiler(P);
            empiler(P,dépiler(P)+aux);
            --taille;
        }
        else
        if (T.tab[i]=="-")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)-aux);
            --taille;
        }
        else
        if (T.tab[i]=="/")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)/aux);
            --taille;

        }
        else
        if (T.tab[i]=="*")
        {
            aux=dépiler(P);
            empiler(P,dépiler(P)*aux);
            --taille;
        }
        else
        if (T.tab[i]=="^")
        {
            aux=dépiler(P);
            empiler(P,puissance(dépiler(P),aux));
            --taille;
        }
        else
        if (T.tab[i]=="RAC")
        {
            empiler(P,std::sqrt(dépiler(P)));
        }

        else
        {
            if (T.tab[i]=="PI")
            {
                empiler(P,3.14159);
            }
            else
            {
                empiler(P,std::stof(T.tab[i]));
            }
            ++taille;
        }
    }
    if(taille==1)
        return dépiler(P);
    else{
        std::cout<<"l'expression est incomplète"<<std::endl;
        return -1;
    }
}


int main()
{
    tab T;
    if(saisie2(T))
        std::cout<<"l'évaluation de la formule est : "<<évaluation(T)<<std::endl;
}
