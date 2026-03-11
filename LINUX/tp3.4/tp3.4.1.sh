# !/ bin / bash
for  ligne in $(exiftool $1) ; do
    fichiers[$i]=$ligne;
    i=$(( i + 1 ));
done


mkdir galerie
placed="First"
mask=.*
mask=$3
for((i=0;i<${#fichiers[@]};++i)) ; do
    
    if [[ ${fichiers[$i]} = "========" ]]  
    then
        if [[ $placed = "False" && $2 = "precise" && $(echo $path|cut -d "/" -f2 ;) == $mask ]] ; then
            echo "veuillez indiquer le date à utiliser, format YYYY:MM:DD"
            read val
            exiftool -overwrite_original -DateTimeOriginal="$(echo $val|cut -d ":" -f1 ;):$(echo $val|cut -d ":" -f2 ;):$(echo $val|cut -d ":" -f3 ;) 00:00:00" $path
            mkdir galerie/$(echo $val|cut -d ":" -f1 ;)
            mkdir galerie/$(echo $val|cut -d ":" -f1 ;)/$(echo $val|cut -d ":" -f2 ;)
            mkdir galerie/$(echo $val|cut -d ":" -f1 ;)/$(echo $val|cut -d ":" -f2 ;)/$(echo $val|cut -d ":" -f3 ;)
            echo "test"
            mv $path galerie/$(echo $val|cut -d ":" -f1 ;)/$(echo $val|cut -d ":" -f2 ;)/$(echo $val|cut -d ":" -f3 ;)
        fi

         
        path=${fichiers[$i+1]}
        placed="False"
    fi
    
    if [[ ${fichiers[$i]} = "Date/Time" && ${fichiers[$i+1]} = "Original" && $(echo $path|cut -d "/" -f2 ;) == $mask ]]  
    then
        mkdir galerie/$(echo ${fichiers[$i+3]}|cut -d ":" -f1 ;)
        mkdir galerie/$(echo ${fichiers[$i+3]}|cut -d ":" -f1 ;)/$(echo ${fichiers[$i+3]}|cut -d ":" -f2 ;)
        mkdir galerie/$(echo ${fichiers[$i+3]}|cut -d ":" -f1 ;)/$(echo ${fichiers[$i+3]}|cut -d ":" -f2 ;)/$(echo ${fichiers[$i+3]}|cut -d ":" -f3 ;)
        mv $path galerie/$(echo ${fichiers[$i+3]}|cut -d ":" -f1 ;)/$(echo ${fichiers[$i+3]}|cut -d ":" -f2 ;)/$(echo ${fichiers[$i+3]}|cut -d ":" -f3 ;)
        placed="True"
    fi
done