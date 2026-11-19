#!/bin/bash
for ((i = 1; ; i++)); do
    echo "Test $i"
    ./gen >in.txt
    ./brut <in.txt >ans.txt
    ./brawa <in.txt >sec.txt
    diff -q ans.txt sec.txt || exit 0
done
