Dalton.prototype.nom="Dalton";
Dalton.prototype.afficher=function (){
    console.log(this.prenom);
    console.log(this.nom);
}

Daltons=[averell,jack,joe,william];

for(dalton of Daltons)
    dalton.afficher();

Daltons.map(d=>d.afficher());
console.log(william.hasOwnProperty("nom"));

for (const key in william) {
    console.log(key,william[key]);
}


Daltons.map(d=>{for (const key in d) {
    console.log(key);
    console.log(d[key]);
}})

delete Dalton.prototype.nom;

Daltons.map(d=>{for (const key in d) {
    console.log(key);
    console.log(d[key]);
}})

Daltons.filter(d=>d[0]=='J').map(d=>d.afficher());