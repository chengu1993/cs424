#!/bin/bash
#PBS -l procs=8,tpn=8,mem=34gb
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
for p in 1 2 4 8;do
	echo "p=$p"
	for run in 1000 2000 4000 8000;do
		echo "N=$run"
		mpiexec --map-by socket -n $p task2 $run
	done
done
