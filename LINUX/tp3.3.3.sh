i=0;


for  ligne in $(df .) ; do
    fichier[$i]=$ligne;
    i=$(( i + 1 ));
done

for ((i=0;i<${#fichier[@]}; ++i)) ; do
    echo "< ${fichier[$i]} >";
done