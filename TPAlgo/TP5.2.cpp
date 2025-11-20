#include "TP5.cpp"


struct Noeud{
    std::string val;
    Noeud* fd,*fg,*p;
};
using arbre = Noeud*;



arbre convertion(arbretab tab ,int i)
{
    Noeud* résultat;
    if (i!=0)
    {
        résultat= new Noeud;
        if (i==tab.indice)
        {
            résultat->p=nullptr;
        }
        résultat->val=tab.Tab[i];
        résultat->fg=convertion(tab,tab.TabGauche[i]);
        résultat->fd=convertion(tab,tab.TabDroit[i]);
        if (résultat->fg!=nullptr)
        {
            résultat->fg->p=résultat;
        }
        if (résultat->fd!=nullptr)
        {
            résultat->fd->p=résultat;
        }
    }
    else 
        résultat=nullptr;
    return résultat;
    
    
    
}


void affiche_arbre(arbre A)
{
    if (A!=nullptr)
    {
        std::cout<<" val : "<<A->val<<std::endl;
        affiche_arbre(A->fg);
        affiche_arbre(A->fd);
    }
}

int hauteur(arbre A)
{
    if (A!=nullptr)
    {
        return 1 + std::max(hauteur(A->fg),hauteur(A->fd));
    }
    return -1;
}
bool isRoot(arbre A)
{
    return (A->p==nullptr);
}

bool isInternNode(arbre A)
{
    return (A->p!=nullptr and (A->fd!= nullptr or A->fg !=nullptr));
}
bool isLeaf(arbre A)
{
    return (A->fd==nullptr and A->fg==nullptr);
}
bool isLeftSon(arbre A)
{
    return (A->p->fg==A);
}
bool isRightSon(arbre A)
{
    return (A->p->fd==A);
}
int nbFeuille(arbre A)
{
    if (!isLeaf(A))
    {
        return  nbFeuille(A->fg)+nbFeuille(A->fd);
    }
    else
    return 1;
}
void affiche_feuille(arbre A)
{
    if (A!=nullptr)
    {
        if (isLeaf(A))
        {
            std::cout<<" val : "<<A->val<<std::endl;
        }
        affiche_feuille(A->fg);
        affiche_feuille(A->fd);
    }
}
int profondeur(arbre A)
{
    if (A->p!=nullptr)
    {
        return 1+profondeur(A->p);
    }
    return -1;
    
}
Noeud* recherche(std::string etiquette, arbre A)
{
    if (A==nullptr)
    {
        return nullptr;
    }
    else
    {
        if (A->val==etiquette)
            return A;
        else
        {  
            Noeud* droite=recherche(etiquette,A->fd);
            Noeud* gauche=recherche(etiquette,A->fg);
            if (droite!=nullptr)
                return droite;
            else
                return gauche;
        }   
    }

    
}
void supprime(arbre &A)
{
    if (A!=nullptr)
    {
        supprime(A->fd);
        supprime(A->fg);
        delete A;
    }
}
int main()
{
    arbretab tab;
    arbre A,B;
    tab=init("./TP5.txt");
    A =convertion(tab,1);
    affiche_feuille(A);
    supprime(A);
    std::cout<<"ok"<<std::endl;
    return 0;
}