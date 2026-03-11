#include<iostream>
using element=char;
struct maillon{
    element val;
    maillon* suiv;
};
using liste = maillon*;
void initfile(liste &l)
{
    l=nullptr;
}
void ajouterpile(liste &l,element e)
{
    liste aux=l;
    l=new maillon;
    l->val=e;
    l->suiv=aux;
}
void ajouterfile(liste &l,element e)
{
    if (l==nullptr)
    {
        l=new maillon;
        l->val=e;
        l->suiv=l;
    }
    else
    {
        liste neuf=new maillon;
        neuf->val=e;
        neuf->suiv=l->suiv;
        l->suiv=neuf;
        l=neuf;
    }
}
void retirerfile(liste &l)
{   liste aux=l->suiv->suiv;
    if (l==l->suiv)
    {
        delete l;
        l=nullptr;
    }
    else
    {
        delete l->suiv;
        l->suiv=aux;
    }
}
element retirerpile(liste &P)
{
    element aux=P->val;
    liste auxp=P;
    P=P->suiv;
    delete auxp;
    return aux;
    
}
element consulterfile(liste &l)
{
    return l->suiv->val;
}
element consulterpile(liste &l)
{
    return l->val;
}

bool estVide(liste &l)
{
    return l==nullptr;
}
liste inverse(liste l)
{
    liste pile=nullptr;
    liste copie=nullptr;
    liste resu=nullptr;
    element e;
    while (l!=nullptr)
    {
        e=consulterfile(l);
        ajouterpile(pile,e);
        ajouterfile(copie,e);
        retirerfile(l);
        std::cout<<e<<std::endl;
    }
    while (pile!=nullptr or copie!=nullptr)
    {
        if (copie!=nullptr)
        {
            ajouterfile(l,consulterfile(copie));
            retirerfile(copie);
        }
        if(pile!=nullptr)
        {
            ajouterfile(resu,retirerpile(pile));
        }
    }
    return resu;
    
}
void affichefile(liste l)
{
    liste aux=l->suiv;
    int i=0;
    
    while (aux!=l)
    {
        std::cout<<"val "<<i<<" : "<<aux->val<<std::endl;
        aux=aux->suiv;
        ++i;
    }
    std::cout<<"val "<<i<<" : "<<l->val<<std::endl;
    
}

int main(){
    liste F ,G;
    initfile(F);
    ajouterfile(F,'a');
    ajouterfile(F,'b');
    ajouterfile(F,'c');
    ajouterfile(F,'d');
    ajouterfile(F,'e');
    affichefile(F);
    G=inverse(F);
    affichefile(G);
}