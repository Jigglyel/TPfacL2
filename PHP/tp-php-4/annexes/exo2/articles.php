<!DOCTYPE html>
<html>
<head>
    <title>Recherche d'articles</title>
    <style>
        html {
            font-size: small;
        }
		form {
			text-align: center;
		}
		fieldset {
			border: 1px solid blue;
			width: 80%;
			margin:auto;
		}
    </style>
</head>
<body>
    <h2 align="center">Recherche d'articles</h2>
	<form action="" method="post">
		<!-- A MODIFIER POUR, LE CAS ECHEANT, RE-AFFICHER LE MOTIF ET L'OPTION CHOISIE -->
		<input type="text" name="motif"/>
		<label for="auteur">Par auteur/année</label>
		<input type="radio" name="cible" id="auteur" value="auteur"/>
		<label for="titre">Par titre</label>
		<input type="radio" name="cible" id="titre" value="titre"/>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>
	<fieldset>
	<legend><strong>Résultat</strong></legend>
    <?php
	// A COMPLETER
    ?>
	</fieldset>
</body>
</html>