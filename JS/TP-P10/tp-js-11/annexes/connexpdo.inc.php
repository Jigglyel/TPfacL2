<?php
require_once 'js.php';

function connexpdo(string $db)
{
    $sgbd = "mysql"; // choix de MySQL
    $host = "localhost";
    $charset = "UTF8";
    // LOGIN ET MOT DE PASSE A CONFIGURER
    $user = ""; // user id
    $pass = ""; // password
    try {
        $pdo = new PDO("$sgbd:host=$host;dbname=$db;charset=$charset", $user, $pass);
        // force le lancement d'exception en cas d'erreurs d'exécution de requêtes SQL
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        return $pdo;
    } catch (PDOException $e) {
        displayException($e);
        exit;
    }
}
?>