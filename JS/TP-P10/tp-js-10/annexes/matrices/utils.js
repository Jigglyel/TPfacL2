/* 
 * Renvoie un entier tiré aléatoirement dans {min,...,max}. 
 */
function tirerEntier(min = 0, max = 1) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

/*
 * Renvoie le tableau [min,...,max]
 */
function générerIntervalle(min, max) {
    let tab = [];
    for (let i = min; i <= max; ++i) {
        tab.push(i);
    }
    return tab;
}

/*
 * Renvoie, sous la forme d'un tableau JS comportant m tableaux de n entiers,
 * une matrice m x n d'entiers tirés aléatoirement dans l'intervalle {0,k} où
 * k=1 si 'binaire' vaut 'true' ou k=m*n sinon.
 */
function générerTableau(m, n, binaire) {
    let tab = [];
    let ceil = binaire ? 1 : m * n;
    générerIntervalle(0, m - 1).forEach(i => tab.push(générerIntervalle(i * n, (i + 1) * n - 1).map(i => tirerEntier(0, ceil)))); // String.fromCharCode)));
    return tab;
}

/*
 * Génère et renvoie un tableau HTML correspondant à la matrice 'tab' (tableau
 * JS de tableaux d'entiers) en insérant en première ligne les numéros des colonnes
 * et en première colonne les numéros des lignes.
 */
function générerTableauHTML(tab) {
    let table = document.createElement("table");
    tab.forEach(function(r) {
        let row = document.createElement("tr");
        r.forEach(function(c) {
            let td = document.createElement("td");
            td.textContent = c;
            row.appendChild(td);
        });
        table.appendChild(row);
    });
    // libellés colonnes
    let header = document.createElement("tr");
    générerIntervalle(1, tab[0].length).forEach(function(i) {
        header.appendChild(document.createElement("th"));
        header.lastElementChild.textContent = i;
    });
    table.insertBefore(header, table.firstElementChild);
    // libellés lignes
    Array.from(table.rows).forEach(function(r, i) {
        r.insertBefore(document.createElement("th"), r.firstElementChild);
        if (i) r.firstElementChild.textContent = i;
    });
    return table;
}

/*
 * Crée, ou remplace si elles existent, les matrices figurant dans les éléments
 * de classe 'mat1' et 'mat2' par deux matrices m x n identiques et générées
 * aléatoirement avec les fonctions générerTableau et générerTableauHTML selon 
 * les dimensions et le type de matrices prescrits par les champs numériques et 
 * le bouton radio coché.
 */
function générerEtat() {
    let mat1 = document.querySelector(".mat1");
    if (mat1.childElementCount != 0) {
        mat1.removeChild(mat1.lastElementChild);
    }
    let mat2 = document.querySelector(".mat2");
    if (mat2.childElementCount != 0) {
        mat2.removeChild(mat2.lastElementChild);
    }

    let dim = Array.from(document.querySelectorAll("input[type='number']")).map(f => parseInt(f.value));
    let checked = document.querySelector("input[type='radio']:checked");
    let tableau1 = générerTableau(dim[0], dim[1], checked.value === "oui");
    let tableau2 = tableau1;
    let tabHTML1 = générerTableauHTML(tableau1);
    let tabHTML2 = générerTableauHTML(tableau2);
    mat1.appendChild(tabHTML1);
    mat2.appendChild(tabHTML2);
}

/*
 * Génère et insère deux matrices identiques dans la page selon les dimensions 
 * et le type de matrices prescrits par défaut dans les champs numériques et 
 * le bouton coché.
 */
let etatInitial = function() {
    générerEtat();
}();