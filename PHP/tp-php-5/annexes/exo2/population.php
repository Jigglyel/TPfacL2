<?php
$couleur=$_GET["couleur"];
$str = <<<HTML
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>TP PHP 5.2 - Villes</title>
<style>
	table { border-collapse: collapse; }
	table, th, tr, td { border: 1px solid black;}
</style>
</head>
<body>
HTML;
echo $str;

$data=file_get_contents("villes.json");
$tab=json_decode($data,true);

echo "<table style=\"background-color:$couleur;\">";
echo "<thead>";
echo "<tr>";
if($couleur==="orange")
{
	uasort($tab,"tri");
	echo "<th> <a href=\"population.php?couleur=red\">  Nom </a></th>";
}
else
	echo "<th> <a href=\"population.php?couleur=orange\">  Nom </a></th>";
echo "<th>Region</th>";
echo "<th>Population</th>";
echo "<th>Préfecture</th>";
echo "</tr>";
echo "</thead>";
echo "<tbody>";

foreach ($tab as $k=>$v){
	echo "<tr>";
	echo "<td>$k</td>";
	foreach($v as $label=>$donnee)
	{
		if($label==="Préfecture")
			if($donnee===TRUE)
				echo "<td>oui</td>";
			else
				echo "<td>non</td>";
		else
			echo "<td>$donnee</td>";
	}
	echo "</tr>";
}

function tri($a,$b):int
{
	if ($a["Région"]<$b["Région"]) {
		return 1;
	}
	else
		if($a["Région"]==$b["Région"])
		{
			if($a["Population"]<$b["Population"])
			{
				return 1;
			}
			else
				return -1;
		}
		else
			return -1;
}



?>
