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
    std ::cout<<d.jour<<"/"<<d.mois<<"/"<<d.année;
}
void affiche_dates(liste dates)
{
    if (dates!=nullptr)
    {
        affiche_date(dates->val);
        std::cout<<" ";
        affiche_dates(dates->suiv);  
    }
    else
        std::cout<<std::endl; 
}

liste init_dates()
{
    return nullptr;
}

historique init_histo()
{
    return nullptr;
}
int compte_date(liste dates)
{
    if (dates!=nullptr)
    {
        return 1 +compte_date(dates->suiv);
    }
    else return 0;
    
}
int compte(historique h)
{
    if (h!=nullptr)
    {
        return compte_date(h->dates)+compte(h->sag)+compte(h->sad);   
    }
    else
        return 0;
    
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
        if (t1[i]>t2[i])
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
        std::cout<<"tirage inedit"<<std::endl;
    }
    else
    {
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

void affiche_date_tirage(historique h,std::string ch)
{
    std::ifstream fic;
        fic.open(ch);
        if (!fic.is_open())
        {
            std::cout<<"problème d'ouverture du fichier"<<std::endl;
        }
        else
        {
            while (fic.good())
            {
                tirage t;
                for (int i = 0; i < 5; i++)
                {
                    fic>>t[i];
                    std::cout<<t[i]<<" ";
                }
                std::cout<<"Tirages du : ";   affiche_tirage_date(h,t);
            }
        }
}

void affiche_historique(historique h)
{
    if (h!=nullptr)
    {affiche_historique(h->sag);
        for (int i = 0; i < 5; i++)
        {
            std::cout<<h->nombres[i]<<" ";
        }
        std::cout<<std::endl;
        
        affiche_historique(h->sad);  
    }
    
}
std::array<int,50> calc_frequ(historique h)
{
    std::array<int,50> t;
        for (int i = 1; i <= 50; i++)
        {
            t[i-1]=0;
        }
    if (h!=nullptr)
    {
        
        for (int i = 0; i < 5; i++)
        {
            t[h->nombres[i]-1]++;
        }
        std::array<int,50> gauche=calc_frequ(h->sag);
        std::array<int,50> droite=calc_frequ(h->sad);
        for (int i = 1; i <= 50; i++)
        {
            t[i-1]+=gauche[i-1]+droite[i-1];
        }
    }
    return t;
    
}
void frequence(historique h)
{
    std::array<int,50> t=calc_frequ(h);
    float total=compte(h);
    for (int i = 0; i < 50; i++)
    {
        std::cout<<"frequence de "<<i+1<<" : "<<(t[i]/(total))*100<<"%"<<std::endl;
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
            fic>>d.jour;
            fic>>d.mois;
            fic>>d.année;
            for (int i = 0; i < 5; i++)
            {
                fic>>t[i];
            }
            ajoute_tirage(H,t,d);
        }
        
        affiche_date_tirage(H,"tirages.txt");
        frequence(H);
    }
    
    
}