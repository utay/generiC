#!/bin/sh

dir=`dirname $0`
cd $dir/..
make
cd test

for f in `find . -name 'test_*'`; do
    if [[ "$f" =~ "*.c" ]] then
        echo $f
        ./$f
        if [ $? -eq 0 ]; then
            echo OK
        else
            echo KO
        fi
        echo
    fi
done
