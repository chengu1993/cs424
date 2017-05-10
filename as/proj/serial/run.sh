#!/bin/bash
#PBS -l procs=4,tpn=2,mem=68gb
#PBS -l walltime=30:00
#PBS -N Poisson_serial
#PBS -r n
#PBS -j oe
#PBS -q cpsc424
module load Langs/Intel/15
pwd
cd $PBS_O_WORKDIR
pwd
cat $PBS_NODEFILE
make
for n in 128 512 1024 2048; do
    time ./poisson $n
done
make clean
