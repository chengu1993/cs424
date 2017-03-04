#!/bin/bash
#PBS -l procs=8,tpn=2,mem=68gb
#PBS -l walltime=15:00
#PBS -N Task4
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
mpiexec --map-by socket -n 7 task4 7633 
