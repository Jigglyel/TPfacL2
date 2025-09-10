 #include<iostream>
 #include<string>
  #include<array>


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
    
    if (L->val.mot==mot)
    {
        L->val.occ++;
    }
    if(L->val.mot<mot)
    {
        ajout(mot,L->suiv);
    }
    else
    {
        ajouteDebut(mot,L);
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
int taille(listeMots L)
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
    int max=0;
    while(L!=nullptr)
    {
        if(max<L->val.mot)
            max=L->val.mot.length();
    }
    return max;
}

int main(){
    listeMots L;
    initialise(L);
    ajouteDebut("saucisse",L);
    ajouteDebut("Mario_Kart",L);
    ajout("Nintendo!",L);
    if (estValide(L))
    {
        std::cout<<"fine"<<std::endl;
    }
    
    affiche(L);
    return 0;
}
