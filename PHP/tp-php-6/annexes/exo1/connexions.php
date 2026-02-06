<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8" />
<title>TP PHP 6.1 - Fichier de log</title>
</head>
<body>
<?php
// Définit le fuseau horaire
date_default_timezone_set('Europe/Brussels');
$file=fopen("connex.txt","a");
fwrite($file,date("d/M H:i:s",time())."\n");
fclose($file);
$file=fopen("connex.txt","r");
while (($ligne=fgets($file)) !==false) {
    echo ($ligne."<br>");
}




// A COMPLETER
?>
</body>
</html>
