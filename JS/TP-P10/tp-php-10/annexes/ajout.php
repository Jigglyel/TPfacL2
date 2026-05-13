<?php
// A COMPLETER: Insertion bdd
$resultat_insert = ""; // à ajuster selon le succès ou l'échec d'une insertion
?>

<!DOCTYPE html>
<html>

<head>
    <title>Catalogue Musical</title>
    <link rel="stylesheet" href="./utils/style.css">
</head>

<body>
    <h1>Catalogue Musical</h1>
    <div id="ajout">
        <h3>Ajouter un album</h3>
        <br>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <label for="artist">Artiste</label>
            <input type="text" name="artist" id="artist">
            <br>
            <label for="album">Album</label>
            <input type="text" name="album" id="album">
            <br>
            <label for="year">Année</label>
            <input type="text" name="year" id="year">
            <br><br>
            <input type="submit" name="ajouter_album" value="Ajouter">
        </form>
        <?php echo $resultat_insert; ?>
    </div>
</body>

</html>