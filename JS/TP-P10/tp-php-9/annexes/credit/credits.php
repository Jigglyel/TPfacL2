<?php
require "connexpdo.inc.php";

// A COMPLETER
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>Proposition</title>
<link rel="stylesheet" type="text/css" href="credits.css">
</head>
<body>
   <form action="<?= "formule.php" ?>" method="post">
      <fieldset>
         <legend>
            Vous souhaitez financer
            <em><?php // A COMPLETER ?></em> pour un montant de <?php // A COMPLETER ?>&euro;</legend>
         <p class="question">Pour le remboursement, choisissez :</p>
         <p>
            <input type="radio" name="remboursement" value="choisi" />
            <label>soit une mensualité de</label>
            <input type="number" name="mensualité" value="1000" min="100" max="100000" step="100" />
            EUR à <?php // A COMPLETER ?>&#37;
         </p>
         <p>
            <input type="radio" name="remboursement" value="proposé" checked />
            <label>soit une durée de crédit proposée dans ce tableau</label>
         </p>
         <table>
            <tr>
               <th>Durée</th>
               <?php // A COMPLETER ?>
            </tr>
            <tr>
               <th>Mensualité (&euro;)</th>
               <?php // A COMPLETER ?>

            </tr>
            <tr>
               <th>Taux mensuel (&#37;)</th>
               <?php // A COMPLETER ?>
            </tr>
         </table>
         <p>
            <input type="submit" name="suivant" value="Suivant" />
            <input type="reset" name="RAZ" />
         </p>
      </fieldset>
   </form>
</body>
</html>
