#include<iostream>
#include<string>

struct date
{
    std::string jour,mois,année;
};

struct individu
{
    std::string nom,prenom;
    date date_de_naissance;
};
struct abGen
{
    individu mec;
    abGen* parent1;
    abGen* parent2;
};
using arbre=abGen*;

individu saisie()
{
    individu mec;
    std::string datnais;
    long unsigned int i=0;
    std::cout<<"veuillez saisir le nom et prenom de l'individu :";
    std::cin>>mec.nom>>mec.prenom;
    std::cout<<"veuillez sasir la date de naissance de l'individu (jour/mois/année) :";
    std::cin>>datnais;
    while (datnais[i]!='/')
    {
        mec.date_de_naissance.jour+=datnais[i];
        ++i;
    }
    ++i;
    while(datnais[i]!='/')
    {
        mec.date_de_naissance.mois+=datnais[i];
        ++i;
    }
    ++i;
    while (i<datnais.length())
    {
        mec.date_de_naissance.année+=datnais[i];
        ++i;
    }
    return mec; 
}


bool isidentique(individu mec1, individu mec2)
{
    return (mec1.nom==mec2.nom and mec1.prenom==mec2.prenom and mec1.date_de_naissance.jour==mec2.date_de_naissance.jour and mec1.date_de_naissance.mois==mec2.date_de_naissance.mois and mec1.date_de_naissance.année==mec2.date_de_naissance.année);
}


abGen* recherche_mec(individu mec ,abGen* arbre)
{
    abGen* résu1;
    abGen* résu2;
    if (arbre!=nullptr)
    {
        if (isidentique(arbre->mec,mec))
        {
            return arbre;
        }
        else
        {
            résu1= recherche_mec(mec,arbre->parent1);
            if (résu1!=nullptr)
            {
                return résu1;
            }
            
            résu2= recherche_mec(mec,arbre->parent2);
            if (résu2!=nullptr)
            {
                return résu2;
            }

        }
    }
    return nullptr;
    
}
//ajout l'indivudu I1 à l'individu I2 dans l'arbre
void ajout_parent(individu I1,individu I2,abGen* &arbre)
{
    abGen* gauche =recherche_mec(I2,arbre)->parent1;
    abGen* droite =recherche_mec(I2,arbre)->parent2;
    if (gauche==nullptr)
    {
        gauche->mec=I1;
    }
    else
    if (droite==nullptr)
    {
        droite->mec=I2;
    }
}

void inverse(abGen*& arbre)
{
    abGen* aux=arbre->parent1;
    arbre->parent1=arbre->parent2;
    arbre->parent2=aux;
}

void affiche_Dude(individu mec)
{
    std::cout<<"prenom : "<<mec.prenom<<std::endl;
    std::cout<<"nom : "<<mec.nom<<std::endl;
    std::cout<<"date de naissance : "<<mec.date_de_naissance.jour<<"/"<<mec.date_de_naissance.mois<<"/"<<mec.date_de_naissance.année;
}

void affiche(arbre A)
{
    if (A->parent1!=nullptr)
    {
        affiche(A->parent1);
    }
    std::cout<<"                    ";
    if (A->parent2!=nullptr)
    {
        affiche(A->parent2);
    }
    std::cout<<"          "<<std::endl<<std::endl<<std::endl<<std::endl;
    affiche_Dude(A->mec);
}


int main(int argc, char const *argv[])
{
    arbre A;
    individu Jérome, adam, eve, rondoudou,minidou, toudoudou,toudoudou2;
    Jérome=saisie();
    adam=saisie();
    eve=saisie();
    A=new abGen;
    A->mec=Jérome;
    A->parent1=nullptr;
    A->parent2=nullptr;
    std::cout<<"ok"<<std::endl;
    ajout_parent(adam,Jérome,A);
    ajout_parent(eve,Jérome,A);
    affiche(A);

    return 0;
}
