function Professeur(nom,prenom,age, interets,matiere)
{
    Personne.call(this, nom,prenom,age,interets);
    this.matiere=matiere;
}
Professeur.prototype.saluer=function(){
    alert("Bonjour, mon nom est "+this.prenom+" j'enseigne l'"+this.matiere);
}
let prof= new Professeur("Barichard","Vincent",206,["ordi","c++","algo"],"algo");

prof.bio();


prof.saluer();