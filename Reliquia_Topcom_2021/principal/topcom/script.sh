#!/bin/bash

if [ -d "outprog" ]; then
  rm -R outprog
  rm prog
fi
mkdir outprog

gcc -o prog main.c -lm

./prog < input/test_1 > outprog/test_1
./prog < input/test_2 > outprog/test_2
./prog < input/test_3 > outprog/test_3
./prog < input/test_4 > outprog/test_4
./prog < input/test_5 > outprog/test_5

diff output/ outprog/