# !/ bin / bash
i=0;
for  nom in $(ls -A .) ; do
    fichier[$i]=$nom
    i=$(( i + 1 ));
done
tier="";

for ((i=0;i<${#fichier[@]}; ++i)) ; do
    for ((j=0;j<${#fichier[@]}; ++j)) ; do
        if (( ${#fichier[$j]}<${#fichier[$(($j+1))]} )) ; then
            tier=${fichier[$j]};
            fichier[$j]=${fichier[$(($j+1))]};
            fichier[$((  $j+1  ))]=$tier;
        fi
    done
done

for ((i=0;i<${#fichier[@]}; ++i)) ; do
echo ${fichier[$i]};

done

