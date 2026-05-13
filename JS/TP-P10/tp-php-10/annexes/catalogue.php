<?php

// A COMPLETER: 
// Récupération des données de la bdd
?>

<!DOCTYPE html>
<html>

<head>
    <title>Catalogue Musical</title>
    <link rel="stylesheet" href="./utils/style.css">
</head>

<body>
    <div id="nav">
        <h1>Catalogue Musical</h1>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <input type="submit" class="nav-btn" name="voir" value="Voir catalogue">
            <input type="button" class="nav-btn" name="stats" value="Statistiques">
        </form>
    </div>

    <hr>

    <div id="contents">

        <div id="albums">
            <?php
            // A COMPLETER: 
            // Génération du tableau
            
            ?>
        </div>

        <div id="songs">
            <h4 id="album-name"></h4>
            <?php
            // A COMPLETER: 
            // Génération d'une liste ordonnée
            ?>
        </div>

        <script src="stats.js"></script>
        <script src="catalogue.js"></script>
    </div>
</body>

</html>