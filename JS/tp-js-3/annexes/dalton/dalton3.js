function Famille(nom)
{
    if (nom==undefined) {
        nom="";
    }
    else
        this.nom=nom;
    this.membres=[]
}

DALTON=new Famille("Dalton");
Famille.prototype.ajouter=function (mec)
{
    this.membres.push(mec.prenom);
}

DALTON.ajouter(averell);
Famille.prototype.ajouter.call(DALTON,jack);

[joe,william].map(d=>Famille.prototype.ajouter.call(DALTON,d));

Famille.prototype.afficher=function(){
    for(prenom of this.membres)
        console.log(prenom);
}

DALTON.afficher();