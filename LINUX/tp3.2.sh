#!/bin/bash
for saucisse in $(find / \( \( -name '*.png' -o -name '*.jpg' \) -a -size +1000k \) 2>/dev/null); do
    taille=$(du -h $saucisse | cut -f 1);
    echo  "$taille # $saucisse";
done