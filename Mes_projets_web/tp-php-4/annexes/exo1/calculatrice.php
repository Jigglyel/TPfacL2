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
                        <?php $v1 = htmlspecialchars($_POST["nb1"] ?? 0);?>
                        <td><label><b> Nombre 1 </b></label> <input type="number" step="1" name="nb1" size="30"
                                value="<?= $v1 ?>" />
                        </td>
                    </tr>
                    <tr>
                        <?php $v2 = htmlspecialchars($_POST["nb2"] ?? 0);?>
                        <td><label><b> Nombre 2 </b></label> <input type="number" step="1" name="nb2" size="30"
                                value="<?= $v2 ?>" />
                        </td>
                    </tr>
                    <tr>
                    <?php
                    $r="";
                    $v3 = htmlspecialchars($_POST["calcul"] ?? "");
                        if($v3==="Addition x+y")
                            $r =$v1+$v2;
                        if($v3==="Soustraction x-y")
                            $r =$v1-$v2;
                        if($v3==="Division x/y")
                        {
                            if($v2!=0)
                            {
                                $r =$v1/$v2;
                            }
                            else
                                $r="impossible";
                        }
                        if($v3==="Puissance x^y")
                            $r =$v1**$v2;
                        echo $r;
                        ?>
                        <td><label><b> Résultat </b></label> <input type="number" step="1" name="result" size="30"
                                value="<?= $r ?>" disabled />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Choisissez ! </b></label>
                            <input type="submit" name="calcul" value="Addition x+y" />&nbsp;&nbsp;&nbsp;
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
