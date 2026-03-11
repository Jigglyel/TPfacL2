<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8"/>
<title>TP PHP 6.2 - Formulaire d'inscription étudiants</title>
</head>
<body style="background-color: #ffcc00;">
<form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
<fieldset>
<legend><b>Inscrivez-vous ou affichez la liste des étudiants</b></legend>
<label>Nom :&nbsp;&nbsp;&nbsp;&nbsp;</label>
<input type="text" name="nom" value="Didact" size=30/><br/><br/>
<label>Prénom : </label>
<input type="text" name="prenom" value="Otto" size=30/><br/><br/>
<label>Groupe :&nbsp;</label>
<select name="groupe"  required="required">
<option value="I1" selected="selected">I1</option>
<option value="I2">I2</option>
<option value="I3">I3</option>
<option value="I4">I4</option>
<option value="I5">I5</option>
<option value="I6">I6</option>
</select><br/><br/>
<input type="submit" value="S'inscrire" name="envoi" />
<input type="submit" value="Lister" name="affiche" />
</fieldset>
</form>
<?php

$nom=$_POST["nom"];
$prenom=$_POST["prenom"];
$groupe=$_POST["groupe"];
$inscription=isset($_POST["envoi"]);
$affiche=isset($_POST["affiche"]);
if ($inscription) {
    $file=fopen("etudiants.csv","a");

    fputcsv($file,[$nom,$prenom,$groupe],";","\"",NULL,PHP_EOL);
    fclose($file);
}
if ($affiche) {
    $file=fopen("etudiants.csv","r+");
    $tab=[];
    while (($ligne=fgetcsv($file,NULL,";","\"")) !==false) {
        $tab[]=$ligne;
}
    echo "<table>";
    echo "<thead>";
    echo "<tr>";
    echo "<td>ID</td><td>Nom</td><td>Prenom</td><td>Groupe</td>";
    echo "</thead>";
    echo "</tr>";
    echo "<tbody>";
    foreach($tab as $i=>$ligne)
    {
        echo "<tr>";
        echo   "<td>$i</td>";
        foreach($ligne as $champ)
        {
            echo   "<td>$champ</td>";
        }
        echo "</tr>";
    }




}
?>
</body>
</html>
