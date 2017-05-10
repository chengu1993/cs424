#!/bin/sh
make
for n in 128 512 1024 2048; do
    time ./serial $n > serial$n.log
done
make clean
