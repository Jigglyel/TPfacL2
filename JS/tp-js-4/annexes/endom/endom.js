truc=document.getElementById("FORM");
truc.textContent="lol";

tab=document.getElementsByTagName("table");
tab[0].style.width="80%";

liste=document.querySelectorAll("dl dd");
Array.from(liste).forEach(element => {element.style.backgroundColor="lightcyan"});

liste=document.querySelectorAll("li");
Array.from(liste).forEach(element => {element.textContent="Hello"});
tab[1].parentNode.removeChild(tab[1]);

lignes=document.querySelectorAll("tr");
lignes[2].parentNode.removeChild(lignes[2]);
lignes=document.querySelectorAll("tr");
console.log(lignes);
Array.from(lignes).forEach(ligne => {ligne.removeChild(ligne.childNodes[3])
    
});



input=document.getElementsByName("h_adr_cp");
console.log(input);
input[0].value="49000";


input=document.getElementsByName("h_hab_options[]");
Array.from(input).forEach(truc => {
    if (truc.value=="garage" || truc.value=="piscine") {
        truc.setAttribute("checked","true");
    }
});
