<!DOCTYPE html>
<html lang="fr">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>TP PHP 4.1 - Calculatrice</title>
</head>

<body>
    <!-- A INSERER : CODE PHP POUR TRAITER LE FORMULAIRE -->

    <h3>Entrez deux nombres : </h3>
    <!-- A MODIFIER : CODE PHP POUR AFFICHER ARGUMENTS ET RESULTAT EVENTUELS  -->
    <form action="<?= $_SERVER["PHP_SELF"] ?>" method="post">
        <fieldset>
            <legend>Calculatrice en ligne</legend>
            <table>
                <tbody>
                    <tr>
                        <td><label><b> Nombre 1 </b></label> <input type="number" step="1" name="nb1" size="30"
                                value="" />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Nombre 2 </b></label> <input type="number" step="1" name="nb2" size="30"
                                value="" />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Résultat </b></label> <input type="number" step="1" name="result" size="30"
                                value="" disabled />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Choisissez ! </b></label> <input type="submit" name="calcul"
                                value="Addition x+y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Soustraction x-y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Division x/y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Puissance x^y" />&nbsp;&nbsp;&nbsp;
                        </td>
                    </tr>
                </tbody>
            </table>
        </fieldset>
    </form>

</html>
