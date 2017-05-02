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
for BLOCK_SIZE in 4 8 16 32 
do

	echo "block_size:$BLOCK_SIZE"
	#case0 and case2
	./matmul 1024 1024 1024 $BLOCK_SIZE $BLOCK_SIZE `cat ~/.cpsc424_gpu`> a0_"$BLOCK_SIZE".log
	./matmul 1024 8192 1024 $BLOCK_SIZE $BLOCK_SIZE `cat ~/.cpsc424_gpu`> a2_"$BLOCK_SIZE".log
    #case1 and case3
	./matmul 8192 8192 8192 $BLOCK_SIZE $BLOCK_SIZE `cat ~/.cpsc424_gpu`> a1_"$BLOCK_SIZE".log
	./matmul 8192 1024 8192 $BLOCK_SIZE $BLOCK_SIZE `cat ~/.cpsc424_gpu`> a3_"$BLOCK_SIZE".log

	#case4
	./matmul 8192 8192 1024 $BLOCK_SIZE $BLOCK_SIZE `cat ~/.cpsc424_gpu`> a4_"$BLOCK_SIZE".log
done
make clean
~ahs3/bin/gpufree

