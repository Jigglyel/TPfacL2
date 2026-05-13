///////// UTILITAIRES ///////////////////////////////////////////////////////////////////

// Masque les "tooltips"
function deactivateTooltips() {
	// A COMPLETER
}

// Renvoie le "tooltip" associé à l'élément elt (ie. l'élément qui suit elt dans sa fratrie) 
// Renvoie false si le "tooltip" n'existe pas
function getTooltip(elt) {
	// A COMPLETER
}

// Fonction booléenne de validation et affichage :
// Si la condition "cond" est vraie : classe "correct" l'élément "elt", masque le "tooltip", et renvoie vrai
// Sinon : classe "incorrect" l'élément "elt", affiche le "tooltip", et renvoie faux
function validate(cond,elt,tooltip) {
	// A COMPLETER
}


///////// ECOUTEURS ///////////////////////////////////////////////////////////////////
// Fonctions booléennes de vérification des champs du formulaire : 1 fonction par champ.
// Chaque fonction est une méthode de l'objet "check" et dénommée selon son champ, 
// e.g. check.gender est la fonction de vérification pour le champ de nom "gender"
var check = {};

check['gender'] = // A COMPLETER
check['lastName'] = // A COMPLETER
check['firstName'] = // A COMPLETER
check['age'] = // A COMPLETER
check['login'] = // A COMPLETER
check['pwd1'] = // A COMPLETER
check['pwd2'] = // A COMPLETER
check['country'] = 	// A COMPLETER


	///////// GESTIONNAIRES D'EVENEMENTS /////////////////////////////////////////////////////
(function() { // IIFE pour éviter les variables globales.
	var myForm = document.querySelector('#myForm');
	var select = document.querySelector('select');

	// A COMPLETER : ENREGISTREMENT DES GESTIONNAIRES POUR LES DIFFERENTS CHAMPS
	// UTILISANT LES DIFFERENTES FONCTIONS DE VERIFICATION. 
})();

///////// DESACTIVATION PAR DEFAUT ///////////////////////////////////////////////////////////////
deactivateTooltips();
