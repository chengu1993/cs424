#!/bin/bash
#PBS -l procs=5,tpn=5,mem=40gb 
#PBS -l walltime=4:00:00
#PBS -N task1
#PBS -r n
#PBS -j oe
#PBS -q cpsc424gpu
 
module load Langs/Intel/15 GPU/Cuda/8.0 module list
pwd
cd $PBS_O_WORKDIR
pwd
cat $PBS_NODEFILE
 
~ahs3/bin/gpuget
make
n=17684
while true; do
	echo "n:$n"
	./matmul $n $n $n 32 32 `cat ~/.cpsc424_gpu`> max$n.log
	n=$(($n+1000))
    if [ $n -lt 0 ]
    then
      break
    fi
done
make clean
~ahs3/bin/gpufree

