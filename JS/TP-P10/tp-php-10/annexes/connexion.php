<?php
require_once './utils/util.php';

function etablir_connexion_bdd(string $db)
{
    $sgbd = "mysql";
    $host = "localhost";
    $port = 3306; // port par défaut de MySQL (à adapter selon votre config et votre choix entre mysql/mariadb)
    $charset = "UTF8";

    // A MODIFIER
    $user = ""; // user id
    $pass = ""; // password

    try {
        $pdo = new pdo(
            "$sgbd:host=$host;port=$port;dbname=$db;charset=$charset",
            $user,
            $pass,
            array(
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION
            )
        );
        return $pdo;
    } catch (PDOException $e) {
        displayException($e);
        exit();
    }
}

?>