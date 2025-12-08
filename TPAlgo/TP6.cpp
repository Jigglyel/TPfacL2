struct Noeud{
    Noeud* fg,*fd;
    int val;
    int hauteur;
};
using arbre =Noeud*;
#include<iostream>
#include<string>
#include<cmath>

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
        std::cout<<"val : "<<A->val<<" adresse pointeur : "<<A<<"; adresse pointeur gauche : "<<A->fg<<"; adresse pointeur droit : "<<A->fd<<" hauteur : "<<A->hauteur<<std::endl;
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
void erease_from_existence(arbre &A,Noeud* &D)
{
    std::cout<<D->val<<" "<<A->val<<std::endl;
    if((D->fg!=nullptr and D->fd==nullptr) or (D->fg==nullptr and D->fd==nullptr))
    {

        if(A->fg==D)
        {
            A->fg=D->fg;
            delete D;std::cout<<"val : "<<A->val<<" adresse pointeur : "<<A<<"; adresse pointeur gauche : "<<A->fg<<"; adresse pointeur droit : "<<A->fd<<std::endl;
        }
        else
        {
            A->fd=D->fg;
            delete D;
        }
    }
    else if(D->fg==nullptr and D->fd!=nullptr)
    {
        if(A->fg==D)
        {
            A->fg=D->fd;
            delete D;
        }
        else
        {
            A->fd=D->fd;
            delete D;
        }
    }
    else if(D->fg!=nullptr and D->fd!=nullptr)
    {
        Noeud *C=D->fg;
        Noeud* P;
        P=D;
        while(C->fd!=nullptr)
        {
            P=C;
            C=C->fd;
        }
        D->val=C->val;
        erease_from_existence(P,C);std::cout<<"val : "<<A->val<<" adresse pointeur : "<<A<<"; adresse pointeur gauche : "<<A->fg<<"; adresse pointeur droit : "<<A->fd<<std::endl;
    }
}
void supprimer(arbre &A,int e)
{
    Noeud* D=nullptr;
    std::cout<<A->val<<std::endl;
    if(A!=nullptr)
    {
        if (A->val==e)
        {
            D=A;
        }
        if(A->fg!=nullptr)
        {
            if(A->fg->val==e)
            {
                D=A->fg;
            }
        }
        if(A->fd!=nullptr)
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


int somme(arbre A, int x)
{

    if(A!=nullptr and A->val<x)
    {
        std::cout<<A->val<<std::endl;
        return A->val+somme(A->fg,x)+somme(A->fd,x);
    }
    else return 0;
}

void fusionner(arbre &A1, arbre A2)
{
    if(A2!=nullptr)
    {
        ajouter(A1,A2->val);
        fusionner(A1,A2->fg);
        fusionner(A1,A2->fd);
    }
}
int hauteur(arbre A)
{
    if(A!=nullptr)
    {
        return 1+std::max(hauteur(A->fg),hauteur(A->fd));
    }
    else
        return -1;
}

bool equilibre(arbre A)
{
    if(A!=nullptr)
    {
        if(hauteur(A->fg)-hauteur(A->fd)<=1 and hauteur(A->fg)-hauteur(A->fd)>=-1 and equilibre(A->fg) and equilibre(A->fd))
            return true;
        else
            return false;
    }
    else
        return true;
}

void supprime(arbre &A)
{
    if(A!=nullptr)
    {
        supprime(A->fg);
        supprime(A->fd);
        std::cout<<"valeur de A : "<<A->val<<" addresse de A : "<<A<<std::endl;
        delete A;
    }
}
int hauteur2(arbre & A)
{
    return A->hauteur;
}

void update(arbre & A)
{
    if(A!=nullptr)
    {
        update(A->fg);
        update(A->fd);
        if(A->fg==nullptr and A->fd!=nullptr)
            A->hauteur=A->fd->hauteur+1;
        else if(A->fd==nullptr and A->fg!=nullptr)
        {
            A->hauteur=A->fg->hauteur+1;
        }
        else if(A->fd==nullptr and A->fg==nullptr)
        {
           A->hauteur=0;
        }
        else
        {
            std::cout<<"lol"<<std::endl;
            A->hauteur=1+std::max(A->fg->hauteur,A->fd->hauteur);
        }
   }
}


int main()
{
    int n1=10;
    int T1[n1] = { 5 , 3 , 7 , 1 , 8 , 10 , 9 ,5 , 7 , 7};
    int T2[n1]=  {15 , 10 , 26 , 7 , 9 , 23 , 13 , 26 , 10 , 26 };
    int T3[] ={11 , 4 , 15 , 3 , 7 , 17 , 6 };
    arbre A=Genere(T1,n1);
    arbre B=Genere(T2,n1);
    arbre C=Genere(T3,7);
    std::cout<<equilibre(A)<<std::endl;
    std::cout<<equilibre(B)<<std::endl;
    std::cout<<equilibre(C)<<std::endl;
    
    update(A);
    affiche(A);
    
}
