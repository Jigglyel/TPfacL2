for path in $(find /  -name '*.jpeg'  2>/dev/null); do
    if ([[ -w $path ]]); then
        echo $path;
        touch ${path/.jpeg/.jpg};
        rm $path;
    fi
done

for path in $(find /  -name '*.tar.gz'  2>/dev/null); do
    if ([[ -w $path ]]); then
        echo $path;
        touch ${path/.tar.gz/.tgz};
        rm $path;
    fi
done
