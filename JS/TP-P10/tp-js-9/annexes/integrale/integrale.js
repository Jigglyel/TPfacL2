// Variable fonctionnelle JS dénotant et implémentant la fonction choisie par le visiteur 
let f = function(x) {
    return x;
};

// Ecouteur du menu déroulant
let selectlistener = document.querySelector("#fx").addEventListener("change", function(e) {
    // A COMPLETER
});


// Renvoie le tableau a = [x1 + ((i * (x2 - x1)) / n) | i = 0..n] 
// qui segmente [x1,x2] en n intervalles contigus et de mêmes tailles
function segmentation(x1, x2, n) {
    // A COMPLETER
    return a;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2]
// obtenue par la méthode des rectangles à GAUCHE basée sur une décomposition en n intervalles
function integrale_rectangle_gauche(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    r = 0.0;
    for (let i = 0; i < n; ++i) {
        r += Math.abs(f(a[i]));
    }

    return (r * (x2 - x1)) / n;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2]
// obtenue par la méthode des rectangles à DROITE basée sur une décomposition en n intervalles
function integrale_rectangle_droite(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    // A COMPLETER
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2] par la méthode des trapèzes
function integrale_trapeze(f, x1, x2, n) {
    return (integrale_rectangle_gauche(f, x1, x2, n) + integrale_rectangle_droite(f, x1, x2, n)) / 2;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2] par la méthode de Simpson
function integrale_simpson(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    let r = 0.0;
    for (let i = 0; i < n; ++i) {
        r += (a[i + 1] - a[i]) / 6 * (f(a[i]) + 4 * f((a[i] + a[i + 1]) / 2) + f(a[i + 1]));
    }

    return r;
}

// Ecouteur du bouton "calculer"
// A COMPLETER


// Ecouteur du bouton "effacer"
// A COMPLETER