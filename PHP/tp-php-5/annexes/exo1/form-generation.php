
<!DOCTYPE html>
<html>
<head>
<title>TP PHP 5.1 - Génération de formulaire</title>
</head>
<body>
<?php
require_once("form-generation.inc.php");
echo open();
echo text("NOm?","nom");

echo text("Prenom?","prenom");
echo checkbox("Lyon","ville","lyon");
echo checkbox("Paris","ville","patsrirjbgi");
echo submit("submit","reset");
echo close();
?>
 </body>
</html>
