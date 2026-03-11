# !/ bin / bash
NomFichier=" ";
NomSortie=" ";
Recursif=0;

if ([[ $1 = "-r" ]]); then
    Recursif=1;
fi
NomFichier=$2;
NomSortie=$3;

echo " Récursif : $Recursif "
echo " Fichier d'entrée : $NomFichier "
echo " Fichier de sortie : $NomSortie "