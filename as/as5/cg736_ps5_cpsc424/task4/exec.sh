#!/bin/sh
for N in 2048 4096 8192 16384 32768
do
./nbody4 $N 1 > "log/nbody4_"$N"_1.log"
./nbody4 $N 8 > "log/nbody4_"$N"_8.log"
#echo $N
done
