#!/bin/sh


for i in `seq 2 16`; do
	echo "$i"
	cat ntb"$i".log | grep "on GPU" >> result.log
done

for i in 32 64 128 256; do
	echo "$i"
	cat ntb"$i".log | grep "on GPU" >> result.log
done
