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
  
./matmul 1024 1024 1024 32 32 32 > base0.log
./matmul 8192 8192 8192 32 256 256 > base1.log
./matmul 1024 8192 1024 32 32 32 > base2.log
./matmul 8192 1024 8192 32 256 256 > base3.log
./matmul 8192 8192 1024 32 32 256 > base4.log

~ahs3/bin/gpufree

