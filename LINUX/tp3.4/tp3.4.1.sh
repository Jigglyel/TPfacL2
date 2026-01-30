# !/ bin / bash
for  ligne in $(exiftool $1) ; do
    fichiers[$i]=$ligne;
    i=$(( i + 1 ));
done




mkdir galerie;
for((i=0;i<${#fichiers[@]};++i)) ; do

    if [[ ${fichiers[$i]} = "========" ]]  
    then
        path=${fichiers[$i+1]}
    fi
    if [[ ${fichiers[$i]} = "Date/Time" && ${fichiers[$i+1]} = "Original" ]] ; 
    then
        mkdir galerie/$(cut -d ":" -f1 ${fichiers[$i+3]};)/$(cut -d ":" -f2 ${fichiers[$i+3]};)/$(cut -d ":" -f3 ${fichiers[$i+3]};)
        mv $path galerie/$(cut -d ":" -f1 ${fichiers[$i+3]};)/$(cut -d ":" -f2 ${fichiers[$i+3]};)/$(cut -d ":" -f3 ${fichiers[$i+3]};)
    fi
done