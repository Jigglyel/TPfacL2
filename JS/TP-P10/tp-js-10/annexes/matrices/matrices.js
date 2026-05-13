/*
 * Quand l'un des deux boutons radio est coché, remplace les 2 matrices
 * existantes par 2 matrices m x n identiques d'entiers tirés aléatoirement 
 * selon les dimensions et le type de matrices prescrits par les champs 
 * numériques et le bouton coché en appelant la fonction générerEtat().
 */
document.querySelectorAll("[type=radio]").forEach(radio=>{
    radio.addEventListener("click",function(){
        générerEtat();
    })
})
// A COMPLETER

/*
 * Remplace les 2 matrices existantes par 2 matrices m x n identiques et
 * tirées aléatoirement à chaque changement de valeur des champs 'Lignes'
 * (m) ou 'Colonnes' (n) en appelant la fonction générerEtat().
 */

document.querySelectorAll("[type=number]").forEach(radio=>{
    radio.addEventListener("change",function(){
        générerEtat();
    })
})

// A COMPLETER


/*
 * Transpose la matrice modélisée par le tableau HTML 'table' passé en argument
 * si elle est carré en "transposant" le tableau (y compris ses libellés), affiche 
 * une alerte sinon.
 */
function transposer(table) {

    
    n=document.getElementById("rows").value
    tab=[]
    for (let j = 0; j < n; j++) {
        tab[j]=[]
    }
    i=-1
    Array.from(table.children).forEach(ligne=>{
        j=-1
            Array.from(ligne.children).forEach(value=>{
                
                if(value.tagName!="TH")
                {      
                    tab[j][i]=parseInt(value.innerText)
                }
                ++j
        })
        
            ++i
    })
    console.log(tab);
    table.parentNode.append(générerTableauHTML(tab))
    table.parentNode.removeChild(table)

    
}

/*
 * Transpose la matrice de l'élément de classe 'mat2' à chaque clic sur le
 * bouton 'Transposer' uniquement si la matrice est carré, émet une alerte
 * sinon. La transposition se fait en appelant la fonction transposer(table).
 */

// A COMPLETER

document.querySelector(".transposer").addEventListener("click",function(){
    table=document.querySelector(".mat2 table")
    console.log(table);
    
    if (document.getElementById("rows").value==document.getElementById("columns").value) {
        transposer(table)
    }
    else
        alert("La matrice n'est pas carrée")
})
/*
 * Permute les lignes i et j (où i<j) du tableau HTML 'table'.
 */
function permuterLignes(table, i, j) {
    
}

/*
 * Permute deux lignes tirées aléatoirement (y compris leurs libellés) dans la 
 * matrice de l'élément de classe 'mat2' à chaque clic sur le bouton 'Permuter'.
 * Les tirages aléatoires s'effectuent par appel à la fonction tirerEntier().
 * La permutation de lignes s'effectue par appel à la fonction permuterLignes().
 */
// A COMPLETER