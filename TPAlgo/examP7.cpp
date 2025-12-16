#include<iostream>
#include<array>
#include<fstream>



struct date
{
    int jour,mois,année;
};


struct maillon
{
    date val;
    maillon* suiv;
};

using liste=maillon*;

using tirage=std::array<int,5>;

struct noeud
{
    liste dates;
    tirage nombres;
    noeud *sad;
    noeud * sag;
};

using historique=noeud*;
void affiche_date(date d)
{
    std ::cout<<d.jour<<"/"<<d.mois<<"/"<<d.année<<std::endl;
}
void affiche_dates(liste dates)
{
    if (dates!=nullptr)
    {
        affiche_date(dates->val);
        affiche_dates(dates->suiv);  
    } 
}

liste init_dates()
{
    return nullptr;
}

historique init_histo()
{
    return nullptr;
}

int compare_date(date d1,date d2)
{
    if (d1.année<d2.année)
    {
        return -1;
    }
    else
    if (d1.année>d2.année)
    {
        return 1;
    }
    else
    {
        if (d1.mois<d2.mois)
        {
            return -1;
        }
        else
        if (d1.mois>d2.mois)
        {
            return 1;
        }
        else
        {
            if (d1.jour<d2.jour)
            {
                return -1;
            }
            else
            if (d1.jour>d2.jour)
            {
                return 1;
            }
            else
                return 0;
        }
    }
}

int compare_tirage(tirage t1, tirage t2)
{
    for (int i = 0; i < 5; i++)
    {
        if (t1[i]<t2[i])
        {
            return -1;
        }
        else
        if (t1[i>t2[i]])
        {
            return 1;
        }
    }
    return 0;
}

void ajoute_date(liste &L,date d)
{
    if (L==nullptr)
    {
        L=new maillon;
        L->val=d;
        L->suiv=nullptr;
    }
    else
    {
        if (compare_date(d,L->val)==-1)
        {
            liste aux;
            aux=L;
            L=new maillon;
            L->val=d;
            L->suiv=aux;
        }
        else
            if (compare_date(d,L->val)!=0)
                ajoute_date(L->suiv,d);
    }       
}
void ajoute_tirage(historique &h,tirage t,date d)
{
    if (h==nullptr)
    {   
        h=new noeud;
        h->dates=nullptr;
        ajoute_date(h->dates,d);
        h->nombres=t;
        h->sad=nullptr;
        h->sag=nullptr;
    }
    else
    {
        if (compare_tirage(t,h->nombres)!=0)
        {
            if (compare_tirage(t,h->nombres)==-1)
            {
                ajoute_tirage(h->sag,t,d);
            }
            else
                ajoute_tirage(h->sad,t,d);
        }
        else
            ajoute_date(h->dates,d);
        
    }
    
}

void affiche_tirage_date(historique h,tirage t)
{
    
    if (h==nullptr)
    {   
        std::cout<<"tirage inédit"<<std::endl;
    }
    else
    {
        affiche_dates(h->dates);
        if (compare_tirage(t,h->nombres)!=0)
        {
            if (compare_tirage(t,h->nombres)==-1)
            {
                affiche_tirage_date(h->sag,t);
            }
            else
                affiche_tirage_date(h->sad,t);
        }
        else
            affiche_dates(h->dates);
        
    }
    
    
}
void affiche_historique(historique h)
{
    if (h!=nullptr)
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout<<h->nombres[i];
        }
        std::cout<<std::endl;
        affiche_historique(h->sag);
        affiche_historique(h->sad);  
    }
    
}
int main()
{
    historique H=init_histo();
    std::ifstream fic;
    fic.open("fake_loto.txt");
    if (!fic.is_open())
    {
        std::cout<<"problème d'ouverture du fichier"<<std::endl;
    }
    else
    {
        while (fic.good())
        {
            date d;
            tirage t;
            fic>>d.année;
            fic>>d.mois;
            fic>>d.jour;
            for (int i = 0; i < 5; i++)
            {
                fic>>t[i];
            }
            ajoute_tirage(H,t,d);
        }
        affiche_historique(H);
        tirage t;
        t[0]=20;
        t[1]=21;
        t[2]=26;
        t[3]=29;
        t[4]=36;
        affiche_tirage_date(H,t);
    }
    
    
}