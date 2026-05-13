<?php
include("connexpdo.inc.php");

try {
    $objdb = connexpdo("bd_inexistante");
    $requete = "SELECT * FROM personne";
    $result = $objdb->query($requete);
    var_dump($result);
} catch (PDOException $e) {
    displayException($e);
}
?>