#!/bin/sh
for N in 2048 4096 8192 16384 32768
do
./nbody3 $N 1 > "log/nbody3_"$N"_1.log"
./nbody3 $N 8 > "log/nbody3_"$N"_8.log"
#echo $N
done
