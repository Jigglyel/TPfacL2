function Personne(nom,prenom,age, interets)
{
    this.nom=nom;
    this.prenom=prenom; 
    this.age=age;
    this.interets=interets;

    this.salutation=function () {
        alert("boujour, je m'appelle "+this.nom +" " + this.prenom);
        
    }
    this.bio=function () {
        let str="";
        this.interets.forEach(interet => {
            str+=interet+" "
            
        });
        str=str.substring(0,str.length-1);
        alert("Nom : "+this.nom + " Prénom : "+this.prenom + " Age : "+this.age + " Centres d'intérets : " + str)
    }
}


let Robert= new Personne("Robert","roblochon",2,["saucisse","raclette","poisson"]);

Robert.salutation();
Robert.bio();
for (const key in Robert) {
    if (Object.prototype.hasOwnProperty.call(Robert, key)) {
        console.log(key);
        
        
    }
    
}

Robert.__proto__.aurevoir=function () {

    alert("boujour, c'était "+Robert.nom +" " + Robert.prenom);
}
Robert.aurevoir()