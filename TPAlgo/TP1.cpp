#include<iostream>
#include<string>
#include<array>
#include<limits>
#include<fstream>


 struct occMot
 {
    std::string mot;
    unsigned int occ;
 };
 struct maillon
 {
    occMot val;
    maillon* suiv;
 };
 using listeMots=maillon*;
 struct tabMots
 {
    std::string* tab;
    unsigned int taille;
 };
 struct occLettre
 {
    char mot;
    unsigned int occ;
 };
 struct tabLettres
 {
    std::array<occLettre,26>tab;
 };

 void initialise(listeMots&L){
    L=nullptr;
 }
 void ajouteDebut (std::string mot,listeMots&L){
    maillon* ajout=new maillon;
    ajout->val.mot=mot;
    ajout->val.occ=1;
    ajout->suiv=L;
    L=ajout;
 }
 void ajout(std::string mot, listeMots & L){
    if (L==nullptr)
    {
        ajouteDebut(mot,L);
    }
    else
    {
        if (L->val.mot==mot)
        {
            L->val.occ++;
        }
        if(L->val.mot<mot)
        {
            ajout(mot,L->suiv);
        }
        if(L->val.mot>mot)
        {
            ajouteDebut(mot,L);
        }
    }
    
 }
void affiche(listeMots L){
    if (L!=nullptr)
    {
        std::cout<<"["<<L->val.mot<<","<<L->val.occ<<"]-->";
        affiche(L->suiv);
    }
    else
        std::cout<<std::endl;
}
void supprime(std::string mot, listeMots& L)
{
    if (L!=nullptr)
    {
        if (L->val.mot==mot)
        {
            maillon*p;
            p=L;
            L=L->suiv;
            delete p;
            supprime(mot,L);
        }
        supprime(mot,L->suiv);
    }
    
}
unsigned int taille(listeMots L)
{
    maillon*q=L;
    unsigned int count=0;;
    while (q!=nullptr)
    {
        q=q->suiv;
        count++;
    }
    return count;
}
int nombreMots(listeMots L)
{
    maillon*q=L;
    unsigned int count=0;;
    while (q!=nullptr)
    {
        q=q->suiv;
        count=count+q->val.occ;
    }
    return count;
}
bool estValide(listeMots L)
{
    if (L==nullptr)
    {
        return true;
    }
    if (L->suiv==nullptr and L->val.occ>=1)
    {
        return true;
    }

    if (L->suiv!=nullptr)
    {
        if (not (L->val.mot<L->suiv->val.mot))
        {
            return false;
        }
    }
    if (L->val.occ<1)
    {
        return false;
    }
    return estValide(L->suiv);
}
int plusLong (listeMots L)
{
    unsigned int max=0;
    while(L!=nullptr)
    {
        if(max<L->val.mot.length())
            max=L->val.mot.length();
        L=L->suiv;
    }
    return max;
}
void afficheLongueur(listeMots L,unsigned int longueur)
{
     while(L!=nullptr)
    {
        if(longueur==L->val.mot.length())
            std::cout<<L->val.mot<<" ";
        L=L->suiv;
    }
        std::cout<<std::endl;
}
void ajoutParLongueur(std::string mot,listeMots &L)
{
   if (L==nullptr)
    {
        ajouteDebut(mot,L);
    }
    else
    {
        if (L->val.mot==mot)
        {
            L->val.occ++;
        }
        if(L->val.mot.length()<mot.length())
        {
            ajoutParLongueur(mot,L->suiv);
        }
        else
        {
            ajouteDebut(mot,L);
        }
    }
    
}
void afficheTriLongueur(listeMots & L)
{
    maillon*q=L;
    maillon*c=nullptr;
    //copie de la liste L dans c grace au pointeur de maillon q tout en récupérant, affichant et supprimant le mot le plus petit
    for (unsigned int i = 0; i < taille(L); i++)
    {
        ajoutParLongueur(q->val.mot,c);
        q=q->suiv;
    }
    affiche(c);
}
void saisie (listeMots & L) {
    std::string mot;
    std::cout<<"quel mode voulez vous choisir? phrase ou liste?"<<std::endl;
    std::cout<<"reponse :";
    std::cin>>mot;
    if (mot=="liste")
    {
        while (mot!="fini")
        {
            std::cout<<"saisissez votre mot ('fini' pour arreter) :";
            std::cin>>mot;
            if (mot=="fini")
            {
                std::cout<<"voulez vous finir ou sasir le mot 'fini'?";
                std::cout<<"réponse(finir ou saisir) :";
                std::cin>>mot;
                if (mot!="finir")
                {
                    mot="fini";
                    ajout(mot,L);
                }
                else
                    mot="fini";
            }
            else
                ajout(mot,L);
        }
        
    }
    else
    {
        mot="";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string aux;
        std::string phrase;
        std::cout<<"saisissez votre phrase:";
        std::getline(std::cin,phrase);
        aux=phrase;
        for (unsigned int i = 0; i < phrase.length(); i++)
        {
            if (phrase[i]==' ')
            {
                ajout(mot,L);
                mot="";
            }
            else
            {
                aux=aux[i];
                mot.append(aux);
            }
        }
        ajout(mot,L);
    }
    
}
void construit (listeMots & L, std::string nomFichier)
{
    std::ifstream fic;
    std::string mot;
    fic.open(nomFichier);
    if (fic.is_open())
        while (fic.good())
        {
            fic>>mot;
            ajout(mot,L);
        }
}
void remplit (tabMots & T, listeMots L)
{
    unsigned int tailleDeL=taille(L);
    T.tab=new std::string[tailleDeL];
    T.taille=0;
    for (unsigned int i = 0; i < tailleDeL; i++)
    {
        T.tab[i]=L->val.mot;
        T.taille++;
        L=L->suiv;
    }
}
void afficheTab (tabMots & T) 
{
    for (unsigned int i = 0; i < T.taille; i++)
    {
        std::cout<<T.tab[i]<<" ";
    }
    std::cout<<std::endl;
}
bool recherche_dichotomique(unsigned int a, unsigned int b,std::string mot,tabMots T){
    unsigned int x=a+b;
    x=x/2;
    if (mot==T.tab[x])
        return true;
    else{
        if (b-a<=1)
            return false;
        else{
            if (mot<T.tab[x])
            {
                return recherche_dichotomique(a,x,mot,T);
            }
            else
                return recherche_dichotomique(x,b,mot,T);
        }
    }
    
}
bool appartient (std::string mot, tabMots T)
{
    return recherche_dichotomique(0,T.taille,mot,T);
}
int main(){
    listeMots L;
    tabMots T;
    std::string mot;
    initialise(L);
    construit(L,"TP1.txt");
    afficheTriLongueur(L);
    remplit(T,L);
    std::cout<<"saisir un mot : ";
    std::cin>>mot;
    if (appartient(mot,T))
    {
        std::cout<<"le mot appartient au texte"<<std::endl;
    }
    else
        std::cout<<"le mot n'appartient pas au texte"<<std::endl;
    return 0;
}
