struct Noeud{
    Noeud* fg,*fd;
    int val;
};
using arbre =Noeud*;
#include<iostream>
#include<string>

void ajouter(arbre &A, int e)
{
    if(A!=nullptr)
    {
        if(e<=A->val)
        {
            ajouter(A->fg,e);
        }
        else
        {
            ajouter(A->fd,e);
        }
    }
    else
    {
        A=new Noeud;
        A->val=e;
        A->fg=nullptr;
        A->fd=nullptr;
    }
}

arbre Genere(int * T1,int n1)
{
    arbre A=nullptr;
    for(int i=0; i<n1;++i)
    {
        ajouter(A,T1[i]);
    }
    return A;
}

void affiche(arbre &A)
{
    if(A!=nullptr)
    {
        
        affiche(A->fg);
        std::cout<<"val : "<<A->val<<" adresse pointeur : "<<A<<"; adresse pointeur gauche : "<<A->fg<<"; adresse pointeur droit : "<<A->fd<<std::endl;
        affiche(A->fd);
    }
}
bool recherche(arbre A ,int e)
{
    if(A==nullptr)
        return false;
    if(A->val==e)
        return true;
    else
    {
        if(e<=A->val)
            return recherche(A->fg,e);
        else
            return recherche(A->fd,e);
    }
    
}
void erease_from_existence(arbre &A,Noeud*& D)
{
    if(D->fg==nullptr and D->fd==nullptr)
        {
            delete D;
        }
    else if(D->fg!=nullptr and D->fd==nullptr)
    {
        
        if(A->fg!=nullptr and A->fg==D)
            A->fg=D->fg;
        else
            A->fd=D->fg;
    }
    else if(D->fg==nullptr and D->fd!=nullptr)
    {
        if(A->fg!=nullptr and A->fg==D)
            A->fg=D->fd;
        else
            A->fd=D->fd;
    }
    else if(D->fg!=nullptr and D->fd!=nullptr)
    {
        Noeud *C=D->fg;
        while(C->fd->fd!=nullptr)
        {
            C=C->fd;
        }
        D->val=C->val;
        erease_from_existence(A,C);
    }
}
void supprimer(arbre &A,int e)
{
    Noeud* D=nullptr;
    if(A!=nullptr)
    {
        if(A->fg->val==e)
        {
            D=A->fg;
        }
        else 
        if(A->fd->val==e)
        {
            D=A->fd;
        }
        if(D!=nullptr)
        {
            erease_from_existence(A,D);
        }
        else
        {
            if(e<=A->val)
                supprimer(A->fg,e);
            else
                supprimer(A->fd,e);    
        }
    }
}
int main()
{
    int n1=10;
    int T1[n1] = { 5 , 3 , 7 , 1 , 8 , 10 , 9 , 5 , 7 , 7};
    arbre A=Genere(T1,n1);
    affiche(A);
    supprimer(A,3);
    affiche(A);
}