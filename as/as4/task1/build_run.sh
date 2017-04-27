#!/bin/bash
#PBS -l procs=1,tpn=1,mem=34gb,walltime=30:00
#PBS -N task1
#PBS -q cpsc424
#PBS -j oe

cd $PBS_O_WORKDIR

module load Langs/Intel/15 MPI/OpenMPI/1.8.6-intel15
make clean
make

for i in 1 2 3 4; do

	./serial < /home/fas/hpcprog/ahs3/cpsc424/assignment4/data/actualdata$i > ./actualdata$i.out

done

make clean
