#!/bin/bash

a=(10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20)
b=(20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10)
c=(5 5 6 6 5 5 6 6 10 10 11 11 10 10 11 11 5 5 6 6 5 5 6 6 10 10 11 11 10 10 11 11)
d=(16 16 16 16 16 16 16 16 8 8 8 8 8 8 8 8 16 16 16 16 16 16 16 16 8 8 8 8 8 8 8 8)
e=(4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5 4 5)
f=(4 5 4 5 5 4 5 4 4 5 4 5 5 4 5 4 4 5 4 5 5 4 5 4 4 5 4 5 5 4 5 4)

r=(1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0)

for ind in `seq 0 31`; do
  out=`./part1 ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}`
  if [ "$out" != "${r[ind]}" ]
  then
    echo "Input:" ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}
	echo "Expected Output:" ${r[$ind]}
    echo "Actual Output:" $out
  fi
done