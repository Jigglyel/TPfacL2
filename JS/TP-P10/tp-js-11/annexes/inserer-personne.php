<!DOCTYPE html >
<html>
<head>
<meta charset="UTF-8" />
<title>Liste des inscrits</title>
<style type="text/css">
table, th, td {
	border-collapse: collapse;
	border-style: solid;
	border-width: 1px;
	text-align: left;
}

td {
	width: 100px;
}
</style>
</head>
<body>
<?php
require ("connexpdo.inc.php");
require ("afficher-tableau.php");
$idcom = connexpdo("l2_tp_personne");

// A COMPLETER
// $_POST['person'] est le tableau associatif des champs transmis

?>
</body>
</html>
