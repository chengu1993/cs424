#!/bin/bash
#PBS -l procs=4,tpn=2,mem=68gb
#PBS -l walltime=1:30
#PBS -N Parallel
#PBS -r n
#PBS -j oe
#PBS -q cpsc424

module load Langs/Intel/15 MPI/OpenMPI/1.8.6-intel15
pwd
cd $PBS_O_WORKDIR
pwd
cat $PBS_NODEFILE
make clean
make
time mpiexec -n 4 task2 
