function Dalton(prenom) {
    this.prenom=prenom;
}

var averell=new Dalton("Averell");

function log( Objet)
{
    console.log(Objet);
    console.log(Objet.prenom);
}
log(averell);

var jack=Object.create(Dalton.prototype);
jack.prenom="Jack";
log(jack);

var joe={
    prenom :"Joe"
}
joe.__proto__=new Dalton;
log(joe);

var json="{ \"prenom\" : \"William\" }";
var william=JSON.parse(json);
william.__proto__=new Dalton;
log(william);
console.log(Dalton.prototype===Object.getPrototypeOf(averell));
console.log(Dalton.prototype===Object.getPrototypeOf(jack));
console.log(Dalton.prototype===Object.getPrototypeOf(joe));
console.log(Dalton.prototype===Object.getPrototypeOf(william));

console.log(william.hasOwnProperty("prenom"));
console.log(Object.getOwnPropertyNames(william));
console.log(Object.keys(william));
for(prop in william){
    console.log(prop);
}
