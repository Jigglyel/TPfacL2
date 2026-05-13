<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>Montant</title>
<link rel="stylesheet" type="text/css" href="accueil.css">
</head>
<body>
   <form action="<?= "credits.php" ?>" method="post">
      <fieldset>
         <legend>Choisissez votre financement </legend>
         <p>
            <span class="question">Type de prêt :</span>
            <span>
               <input type="radio" name="prêt" value="auto" checked />
               <label>Auto</label>
               <input type="radio" name="prêt" value="habitat" />
               <label>Habitat</label>
            </span>
         </p>
         <label class="question">Montant souhaité :</label>
         <input type="number" name="montant" value="5000" min="0" max="1000000" step="1000" required />
         <p class="tooltip">
            &euro;
            <span class="tooltiptext">montant total, ou part à financer</span>
         </p>
         <p>
            <input type="submit" name="suivant" value="Suivant" />
            <input type="reset" value="RAZ" />
         </p>
      </fieldset>
   </form>
</body>
</html>
