// Question 1 : Coloration
document.body.style.backgroundColor="Black";
document.getElementById("intro").style.backgroundColor="Orange"
document.getElementById("sondage").style.backgroundColor="Red"

// Question 2 : Centrer images de la div intro 
images =document.querySelectorAll("#intro img")
images.forEach(image => {
    image.classList="center"
    
});

// Question 3 : Ajout indication sondage
inputs =document.querySelectorAll("#sondage input")
console.log(inputs);

inputs.forEach(input => {
    if(input.type=="mail")
        input.value="nom.prenom@univ-angers.fr";

    if(input.type=="radio" && input.value=="non")
    {
        input.checked=true;
        input.label="No"
    }
    if(input.type=="radio" && input.value=="oui")
    {
        input.label="Oui"
    }
        

    
});

// Question 4 : Ajout d'une description textuelle aux images

images =document.querySelectorAll("img")
images.forEach(image => {
    txt="Image";
    parent=image.parentNode;
    while (parent!=document.body) {
        txt+="-"+parent.nodeName+"("+parent.id+")";
        parent=parent.parentNode;
    }
    image.setAttribute("alt",txt);
    
    
});
