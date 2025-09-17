#include<iostream>
#include<string>
#include<fstream>
struct maillon
{
    int element;
    maillon* suiv;
    maillon* prec;

};

struct liste{
maillon* tete;
maillon* queue;
};

using element=int;
void creer(liste &L)
{
    L.tete=nullptr;
    L.queue=nullptr;

}
bool is_vide(liste &L)
{
    if(L.tete==nullptr and L.queue==nullptr)
        return true;
    else
        return false;
}

void insérer_début(element e,liste &L)
{
    
    if (is_vide(L))
    {
        L.tete=new maillon;
        L.tete->element=e;
        L.queue=L.tete;
    }
    else{
        maillon* tier;
        tier=L.tete;
        L.tete=new maillon;
        L.tete->element=e;
        L.tete->suiv=tier;
        L.tete->suiv->prec=L.tete;
        L.tete->prec=nullptr;
    }
    
    
}
void affiche_queue(liste L)
{
    std::cout<<"voici la queue : "<<"["<<L.queue->element<<"| "<<"]-->"<<std::endl;
}
void affiche_tete(liste L)
{
    std::cout<<"voici la tete : "<<"["<<L.tete->element<<"| "<<"]-->"<<std::endl;
}

void insérer_fin(element e,liste &L)
{
    
    if (is_vide(L))
    {
        L.tete=new maillon;
        L.tete->element=e;
        L.queue=L.tete;
        
    }
    else{
        L.queue->suiv=new maillon;
        L.queue->suiv->element=e;
        L.queue->suiv->suiv=nullptr;
        L.queue->suiv->prec=L.queue;
        L.queue=L.queue->suiv;
    }
}
void affiche(liste L)
{
    if (L.tete!=L.queue->suiv)
    {
        std::cout<<"["<<L.tete->element<<"| "<<"-]-->";
        L.tete=L.tete->suiv;
        affiche(L);
    }
    else
        std::cout<<std::endl;
     
}
void affiche_it(const liste &L)
{
    maillon*tier=L.tete;
    while (tier!=L.queue->suiv)
    {
        std::cout<<"["<<tier->element<<"| "<<"-]-->";
        tier=tier->suiv;
    }
    std::cout<<std::endl;
}
void affiche_reverse(liste L)
{
    if (L.tete->prec!=L.queue)
    {
        std::cout<<"["<<L.queue->element<<"| "<<"-]-->";
        L.queue=L.queue->prec;
        affiche_reverse(L);
    }
    else
        std::cout<<std::endl;
}
void affiche_reverse_it(const liste &L)
{
    maillon*tier=L.queue;
    while (L.tete->prec!=tier)
    {
        std::cout<<"["<<tier->element<<"| "<<"-]-->";
        tier=tier->prec;
    }
    std::cout<<std::endl;
}
int longueur(liste L)
{
    if (L.tete!=L.queue->suiv)
    {
        L.tete=L.tete->suiv;
        return(1)+longueur(L);
    }
    else
        return 0;
}
void supprime_queue(liste &L)
{
    L.queue->prec->suiv=nullptr;
    L.queue=L.queue->prec;
    delete L.queue->suiv;
}
void supprime_tete(liste &L)
{
    L.tete->suiv->prec=nullptr;
    L.tete=L.tete->suiv;
    delete L.tete->prec;
}
maillon* recherche(element e,liste &L)
{
    maillon*tier=L.tete;
    while (tier!=L.queue->suiv)
    {
        if (tier->element==e)
        {
            return tier;
        }
        tier=tier->suiv;
    }
    return nullptr;
}
void insere_apres(element x, element y,liste &L)
{
    maillon* adresse=recherche(x,L);
    if (adresse!=nullptr)
    {
        if (adresse->suiv==nullptr)
        {
            insérer_fin(y,L);
        }
        else
            if (adresse!=nullptr)
            {
                maillon* tier=adresse->suiv;
                adresse->suiv=new maillon;
                adresse->suiv->element=y;
                adresse->suiv->suiv=tier;
                adresse->suiv->prec=adresse;
                tier->prec=adresse->suiv;
            }
    }
}
void insere_avant(element x, element y,liste &L)
{
    maillon* adresse=recherche(x,L);
    if (adresse!=nullptr)
    {
        if (adresse->prec==nullptr)
        {
            insérer_début(y,L);
        }
        else
            if (adresse!=nullptr)
            {
                maillon* tier=adresse->prec;
                adresse->prec=new maillon;
                adresse->prec->element=y;
                adresse->prec->prec=tier;
                adresse->prec->suiv=adresse;
                tier->suiv=adresse->prec;
            }
    }
}
void supprime_x(element x,liste &L)
{
    maillon* adresse=recherche(x,L);
        if (adresse!=nullptr)
        {
            if (adresse->prec==nullptr)
            {
                L.tete=adresse->suiv;
            }
            else
            {
                adresse->prec->suiv=adresse->suiv;
            }
            if (adresse->suiv==nullptr)
            {
                L.queue=adresse->prec;
            }
            if (adresse->suiv!=nullptr)
            {
                adresse->suiv->prec=adresse->prec;
            }
            delete adresse;
        }
}
void supprime_everything(liste &L)
{
    maillon*tier=L.tete->suiv;
    while (L.tete!=L.queue)
    {
        delete L.tete;
        L.tete=tier;
        tier=L.tete->suiv;
    }
    creer(L);
}
void supprime_a_partir(maillon *p,liste L)
{
    maillon*tier=p->suiv;
    L.tete=p;
    L.tete->suiv=nullptr;
    while (L.tete!=L.queue)
    {
        delete L.tete;
        L.tete=tier;
        tier=L.tete->suiv;
    }
}
int main(){
    liste L;
    creer(L);
    insérer_fin(9,L);
    
    
    insérer_fin(10,L);
    insérer_début(0,L);
    insérer_début(2,L);
    insere_apres(11,11,L);
    insere_avant(0,-1,L);
    
    affiche_reverse_it(L);


    affiche_it(L);
    affiche_reverse_it(L);
    supprime_a_partir(recherche(2,L),L);
    affiche_it(L);



    return 0;
}