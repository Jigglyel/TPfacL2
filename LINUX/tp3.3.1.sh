# !/ bin / bash
fichier=$(ls -A . );
i=0;
tier=0;
for (( j=0; j < ${#fichier}; ++j )); do
    while ( $fichier[$i] < $fichier[($i+1)] ); do
        tier=$fichier[$i];
        fichier[$i]=$fichier[($i+1)];
        fichier[$i+1]=$tier;
        i++;
    done
done
echo $fichier;