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
		<?php $v0 = htmlspecialchars($_POST["text"] ?? "");?>
		<input type="text" name="motif" value="<?= $v0 ?>"/>
		<label for="auteur">Par auteur/année</label>
		<?php $v1 = htmlspecialchars($_POST["cible"] ?? 0);?>
		<input type="radio" name="cible" id="auteur" value="<?= $v1 ?>"/>
		<label for="titre">Par titre</label>
		<?php $v2 = htmlspecialchars($_POST["cible"] ?? 0);?>
		<input type="radio" name="cible" id="titre" value="<?= $v2 ?>"/>
		<?php $v3 = htmlspecialchars($_POST["submit"] ?? 0);?>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>
	<fieldset>
	<legend><strong>Résultat</strong></legend>
    <?php
		$fichier=fopen("articles.txt", "r");
		$i=0;
		$contenu=[];
		while ( ($ligne = fgets($fichier)) !== FALSE )
		{
9 				$contenu[$i]=$ligne;
				++$i;
		}
		if($v3==="Rechercher")
			foreach($contenu as $ligne)
				if(preg_match($v0, $ligne ))
				{
					echo $ligne;
				}


			?>
	</fieldset>
</body>
</html>
