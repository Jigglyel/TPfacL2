
caca=$1;
for (( j=0; j < ${#caca}; ++j )); do
    for (( i=0; i<${caca:j:1} ; i++ )); do
        echo -n '*';
    done
    echo
done