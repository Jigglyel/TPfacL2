#include <iostream>
#include <fstream>

/**
 * Représente un enregistrement (une ligne) de la table de base de données
 */
struct EnregistrementBDD {
    std::string id;
    std::string prenom;
    std::string nom;
    int age;
};

/**
 * Les valeurs de la table sont stockées dans une liste chaînée.
 * MaillonBDD est un maillon de cette liste simplement chaînée.
 */
struct MaillonBDD {
    EnregistrementBDD enreg;
    MaillonBDD *suiv;
};
using ListeBDD = MaillonBDD*;

/**
 * L'index unique est représenté grâce à un Arbre Binaire de Recherche.
 * NoeudIU est un nœud de cet ABR.
 * Attention : il ne stocke pas directement la valeur indexée, mais un pointeur vers le maillon.
 */
struct NoeudIU {
    MaillonBDD *maillon;
    NoeudIU *sag;
    NoeudIU *sad;
};
using IndexUnique = NoeudIU *;

/**
 * Une table de base de données contient les valeurs (liste des différentes lignes) et un index unique.
 */
struct TableBDD {
    IndexUnique index;
    ListeBDD valeurs;
};

/**
 * Crée un enregistrement (une ligne de la table de base de données) à partir des informations fourniées en paramètre.
 */
EnregistrementBDD creeEnregistrement(std::string id, std::string prenom, std::string nom, int age) {
    EnregistrementBDD e;
    
    e.id = id;
    e.prenom = prenom;
    e.nom = nom;
    e.age = age;
    
    return e;
}

void initTable(TableBDD & table)
{
    table.index=nullptr;
    table.valeurs=nullptr;
}
bool ajoutIU(IndexUnique & iu, MaillonBDD *m)
{
    if (iu!=nullptr)
    {
        if (iu->maillon==m)
        {
            return false;
        }
        
        ajoutIU(iu->sag,m);
        ajoutIU(iu->sad,m);
    }
    else

    {
        iu=new NoeudIU;
        iu->sad=nullptr;
        iu->sag=nullptr;
        iu->maillon=m;
        return true;
    }
    
}

bool ajoutTable(TableBDD & table, EnregistrementBDD e)
{
    ListeBDD aux=table.valeurs;
    while( aux!=nullptr)
    {
        if (aux->enreg.id==e.id)
        {
            return false;
        }
        else
        {
            aux=aux->suiv;
        }
    }
    aux=new MaillonBDD;
    aux->enreg=e;
    aux->suiv=nullptr;
    ajoutIU(table.index,aux);
    return true;
    
}
void charge(TableBDD & table, std::string nomFichier)
{
    std::ifstream fic;
    fic.open(nomFichier);
    EnregistrementBDD e;
    if (!fic.is_open())
    {
        std::cout<<"echec d'ouverture du fichier"<<std::endl;
    }
    while (fic.good())
    {
        fic>>e.id;
        fic>>e.nom;
        fic>>e.prenom;
        fic>>e.age;
        ajoutTable(table,e);
    }
       
}
MaillonBDD * recherche(IndexUnique iu, std::string id)
{
    if (iu==nullptr)
    {
        return nullptr;
    }
    else
    {
        if (iu->maillon->enreg.id==id)
        {
            return iu->maillon;
        }
        else {
            recherche(iu->sad,id);
            recherche(iu->sag,id);
        }
        
    }
}
void supprimeIU(IndexUnique & iu, std::string id)
{
    if (iu!=nullptr)
    {
        if (iu->maillon->enreg.id==id)
        {
            if (iu->sad==nullptr and iu->sag==nullptr)
            {
                delete iu;
            }
            else
            {
                if (iu->sad==nullptr)
                {
                    IndexUnique tier=iu;
                    iu
                }
                
            }
            
        }
        
    }
    
}
// Pour vos tests :
int main() {
    
    
    return 0;
}