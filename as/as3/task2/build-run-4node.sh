#!/bin/bash
#PBS -l procs=8,tpn=2,mem=68gb
#PBS -l walltime=15:00
#PBS -N Task2
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
echo "p=8"
for run in 4000 8000;do
	mpiexec --map-by socket -n 8 task2 $run
done
