// Tableau

function creerTableau(N) {
	// Tableau nu
	// Q1

	// Coefficients
	// Q2

	// Abbréviations
	// Q3
}

// Listeners
window.addEventListener("load", function () {
	var input = document.querySelector("INPUT[type=number]");
	var N = parseInt(input.value);
	creerTableau(N + 1);
})

document.querySelector("INPUT[type=number]").addEventListener("change", function (e) {
	var N = parseInt(e.target.value);
	var div = document.querySelector("DIV");
	var table = div.querySelector("TABLE");
	div.removeChild(table);
	creerTableau(N + 1);

})