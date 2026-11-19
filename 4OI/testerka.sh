#!/bin/bash
g++ f1.cpp -o f1
g++ f2.cpp -o f2
inp1="out1.txt"
inp2="out2.txt"
./f1 >"$inp1"
./f2 >"$inp2"
if diff "$inp1" "$inp2" >/dev/null; then
  echo "BOMBOKLAT"
else
  echo "O HELL NAH"
fi
