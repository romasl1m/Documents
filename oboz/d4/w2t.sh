#!/bin/bash
for ((i = 1; i < 10; i++)); do
  echo "Test $i"
  ./testw2 >inp.txt
  ./interaktor inp.txt ./interaktor_rozwiazanie
done
