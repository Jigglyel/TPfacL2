<?php

// code HTML de champ texte mono-ligne
function text(string $libtexte, string $nomtexte): string
{
    return "<label for=\"$nomtexte\">$libtexte</label>
        <input type=\"texte\" name=\"$nomtexte\" id=\"$nomtexte\">";

}

// code HTML de bouton de soumission
function submit(string $libsubmit, string $libreset): string
{
    return
     "<input type=\"submit\" value=\"$libsubmit\" >
     <input type=\"submit\" value=\"$libreset\" >";
}

// A ETENDRE

function checkbox(string $libelle, string $nom, string $value):string
{
    return "<label for=\"$nom\">$libelle</label>
        <input type=\"radio\" id=\"$nom\" name=\"$nom\" value=\"$value\">";
}

function open():string
{
    return "<form action=\"traiter.php\" method=\"post\">";
}
function close():string
{
    return "</form>";
}
?>
