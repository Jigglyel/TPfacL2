#include"TP5.2.cpp"



file init_file()
{
    return nullptr;
}
bool is_file_vide(file F)
{
    return F==nullptr;
}
void ajouter(file & F,char e)
{
    if (F==nullptr)
    {
        F=new maillon;
        F->suiv=F;
        F->val=e;
    }
    else
    {
        maillon* aux=F;
        F=new maillon;
        F->suiv=aux->suiv;
        F->val=e;
        aux->suiv=F;
    }
}
void supprimer(file & F)
{
    if (F!=nullptr)
    {
        if (F->suiv==F)
        {
            delete F;
            F=nullptr;
        }
        else
        {
            maillon* aux=F->suiv->suiv;
            delete F->suiv;
            F->suiv=aux;
        }
        
    }
}
char consulter(file F)
{
    return F->suiv->val;
}
void ajoute_commande(Noeud* &magasin)
{
    if (magasin->p!=nullptr)
    {
        if (magasin->p->fg==magasin)
        {
            ajouter(magasin->p->F,'G');
        }
        else
        {
            ajouter(magasin->p->F,'D');
        }
        ajoute_commande(magasin->p);

    }
}
void commande(arbre &A, std::string etiquette)
{
    Noeud *magasin =recherche(etiquette,A);
    if (magasin!=nullptr)
    {
        ajoute_commande(magasin);
    }
}
void livraison(arbre &A)
{
    if (A!=nullptr)
    {
        if (A->F!=nullptr)
        {
            std::cout<<A->val<<"=>";
            char direction =consulter(A->F);
            supprimer(A->F);
            if (direction=='G')
            {
                livraison(A->fg);
            }
            else
            {
                livraison(A->fd);
            }
        }
        else
            std::cout<<A->val<<std::endl;
    }
}
void affilcher(file F)
{
    file aux=F->suiv;
    std::cout<<aux->val<<" ";
    aux=aux->suiv;
    while (aux!=F->suiv)
    {
        std::cout<<aux->val<<" ";
        aux=aux->suiv;
    }
    std::cout<<std::endl;
    
}

void etat_commandes(arbre A)
{
    if (A!=nullptr)
    {
        if (A->F!=nullptr)
        {
            std::cout<<A->val<<" : ";
            affilcher(A->F);
        }
        etat_commandes(A->fd);
        etat_commandes(A->fg);
    }
    
}
void simulation(arbre &A)
{
    commande(A,"magasin_1");
    commande(A,"magasin_5");
    commande(A,"magasin_1");
    commande(A,"magasin_4");
    commande(A,"magasin_4");
    commande(A,"magasin_2");
    commande(A,"magasin_3");
    commande(A,"magasin_5");
    livraison(A);
    livraison(A);
    livraison(A);
    livraison(A);
    livraison(A);
    livraison(A);
    livraison(A);
    livraison(A);
}
int main()
{
    arbretab tab;
    arbre A;
    tab=init("./TP5.txt");
    A =convertion(tab,1);
    simulation(A);
    supprime(A);
    return 0;
}