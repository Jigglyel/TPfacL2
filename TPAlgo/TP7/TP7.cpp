#include<iostream>
#include<string>
#include<fstream>
struct occMot{
    std::string mot;
    int occ;
};

struct alvéole{
    occMot val;
    bool occupe;
    int suiv;

};

struct tableHachage{
    alvéole* T;
    int m;
    int posLibre;
};


tableHachage initialisation(int m)
{
    tableHachage tab;
    int r=m*(1+0.15);
    tab.T=new alvéole[m+r];
    tab.posLibre=m+r-1;
    tab.m=m;
    for(int i=0;i<m+r;++i)
    {
        tab.T[i].occupe=false;
        tab.T[i].suiv=-1;
    }
    return tab;
}


int hache(std::string s,int m)
{
    int h0=5381;
    for(unsigned int i=0;i<s.length();++i)
    {
        h0=(33*h0 + int(s[i]))%m;
    }
    return h0;
}


void ajout( tableHachage &tab,std::string s)
{
    int index=hache(s,tab.m);
    bool placed=false;
    //si c'est pas occupé
    if(!tab.T[index].occupe)
    {
        tab.T[index].val.mot=s;
        tab.T[index].val.occ=1;
        tab.T[index].occupe=true;
    }
    else
    {
        if(tab.T[index].val.mot==s)
            {
                tab.T[index].val.occ++;
                placed=true;
            }
        //s'il y a un suivant
        while(!(tab.T[index].suiv==-1) and !placed)
        {
            if(tab.T[index].val.mot==s)
            {
                tab.T[index].val.occ++;
                placed=true;
            }
            else
            {
                index=tab.T[index].suiv;
            }
        }
        if(!placed)
        {
            
            while(tab.T[tab.posLibre].occupe==true and tab.posLibre>=0)
            {
                tab.posLibre--;
                std::cout<<tab.posLibre<<std::endl;
            }
            if(tab.posLibre>=0)
            {
                tab.T[index].suiv=tab.posLibre;
                tab.T[tab.posLibre].val.mot=s;
                tab.T[index].val.occ=1;
                tab.T[tab.posLibre].occupe=true;
                tab.posLibre--;
            }
        }
    }
}
int nbOcc(tableHachage tab,std::string s)
{
    int index=hache(s,tab.m);
    while(tab.T[index].val.mot!=s)
    {
        if(tab.T[index].suiv==-1)
            return -1;
        else
            index=tab.T[index].suiv;
    }
    return tab.T[index].val.occ;
}

void affiche(tableHachage tab)
{
    int remplie=0,remplie2=0;
    float m=tab.m;
    for(int i=0;i<m*1.15;++i)
    {
        if(tab.T[i].val.mot!="")
        {
            std::cout<<tab.T[i].val.mot<<" "<<tab.T[i].val.occ<<" "<<tab.T[i].suiv<<std::endl;
            if(i<m)
            {
                remplie++;
            }
            else
                remplie2++;
        }
    }
    int max=0,index,count=0;
    for(int i=0;i<m*1.15;++i)
    {
        if(!tab.T[i].occupe)
        {
            index=i;
            while(tab.T[index].suiv!=-1)
            {
                index=tab.T[index].suiv;
                std::cout<<"lol"<<std::endl;
                count++;
            }
            if(count>max)
            {
                max=count;
            }
            count=0;
        }
    }
    std::cout<<"facteur de remplissage de la zone primaire : "<<remplie/m*100<<"%"<<std::endl;
    std::cout<<"facteur de remplissage de la zone reserve : "<<remplie2/(m*1.15-m)*100<<"%"<<std::endl;
    std::cout<<"facteur de remplissage total: "<<(remplie+remplie2)/m*1.15*100<<"%"<<std::endl;
    std::cout<<"plus grand chaînage : "<<max<<std::endl;
}
int main()
{
    tableHachage t =initialisation(10000);
    std::ifstream fic;
    fic.open("bouledesuif.txt");
    std::string mot;
    if(fic.is_open())
        while(fic.good())
        {
            fic>>mot;
            ajout(t,mot);
        }
    else
    {
        std::cout<<"fichier non ouvert"<<std::endl;
    }
    affiche(t);
    return 0;
    
}


