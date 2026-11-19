#!/bin/bash
set -e
for ((i = 1; ; i++)); do
    echo "test $i"
    ./gen >in.txt
    ./brut <in.txt >ans.txt
    ./skoki <in.txt >out.txt
    diff -q ans.txt out.txt || {
        echo "files are different"
        exit 0
    }
done
