#!/bin/bash
for ((i = 1; ; i++)); do
    echo "Test $i"
    ./gen >in.txt
    ./test <in.txt >ans.txt
    ./sanae <in.txt >sec.txt
    diff -q ans.txt sec.txt || exit 0
done
