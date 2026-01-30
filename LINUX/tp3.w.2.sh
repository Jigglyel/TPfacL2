save=$IFS;

IFS=$'\r\n';
i=0;

for  ligne in $(cat $1) ; do
    fichier[$i]=$ligne;
    i=$(( i + 1 ));
done

for ((i=0;i<${#fichier[@]}; ++i)) ; do
    echo "< ${fichier[$i]} >";
done
IFS=$save;