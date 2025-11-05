#include<iostream>
using element=int;
struct maillon{
    element val;
    maillon* suiv;
    maillon *prec;
};



using liste= maillon*;
bool inserer (int x, int n, liste &l){
    maillon*copie=l;
    maillon*copie2;
    if (n==1)
        {
            l =new maillon;
            l->val=x;
            l->prec=nullptr;
            l->suiv=copie;
            return 1;
        }
    else
    {
        while (n>2)
        {
            if (copie==nullptr)
                return 0;
            else
            {
                copie=copie->suiv;
                n--;
            }
        }
    copie2=copie;
    copie=new maillon;
    copie->val=x;
    copie->prec=copie2;
    copie->suiv=copie2->suiv;
    if (copie2->suiv!=nullptr)
    {
        copie2->suiv->prec=copie;
    }
    copie2->suiv=copie;
    }
    return 1;
    
}
void affiche(liste L)
{
    if (L!= nullptr)
    {
        std::cout<<"val : "<<L->val<<std::endl;
        affiche(L->suiv);
    }
    
}
int main()
{
    liste L;
    L=nullptr;
    inserer(5,1,L);
    inserer(7,2,L);
    inserer(6,2,L);
    affiche(L);
    return 0;
}