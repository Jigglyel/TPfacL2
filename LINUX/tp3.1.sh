#!/bin/bash
echo "listes des commandes :";
echo "1-afficher la date";
echo "2-afficher nb personnes connectés";
echo "3-taille disponible";
read input;

case $input in
    1)
    date
    ;;
    2)
    echo $USER| wc -l
    ;;
    3)
    free
    ;;

esac