#!/bin/bash
#PBS -l procs=5,tpn=5,mem=40gb 
#PBS -l walltime=4:00:00
#PBS -N task1
#PBS -r n
#PBS -j oe
#PBS -q cpsc424gpu
 
#module load Langs/Intel/15 GPU/Cuda/8.0 module list
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
	dim_x=$((1024/$BLOCK_SIZE))
    dim_y=$((1024/$BLOCK_SIZE))
	echo "dim_x:$dim_x"
	echo "dim_y:$dim_y"
	./matmul 1024 1024 1024 $BLOCK_SIZE $dim_x $dim_y `cat ~/.cpsc424_gpu`> a0_"$BLOCK_SIZE"_"$dim_x"_"$dim_y".log
	./matmul 1024 8192 1024 $BLOCK_SIZE $dim_x $dim_y `cat ~/.cpsc424_gpu`> a2_"$BLOCK_SIZE"_"$dim_x"_"$dim_y".log
    #case1 and case3
	dim_x=$((8192/$BLOCK_SIZE))
	dim_y=$((8192/$BLOCK_SIZE))
	echo "dim_x:$dim_x"
	echo "dim_y:$dim_y"
	./matmul 8192 8192 8192 $BLOCK_SIZE $dim_x $dim_y `cat ~/.cpsc424_gpu`> a1_"$dim_x"_"$dim_y".log
	./matmul 8192 1024 8192 $BLOCK_SIZE $dim_x $dim_y `cat ~/.cpsc424_gpu`> a3_"$dim_x"_"$dim_y".log

	#case4
	dim_x=$((1024/$BLOCK_SIZE))
	dim_y=$((8192/$BLOCK_SIZE))
	echo "dim_x:$dim_x"
	echo "dim_y:$dim_y"
	./matmul 8192 8192 1024 $BLOCK_SIZE $dim_x $dim_y `cat ~/.cpsc424_gpu`> a4_"$dim_x"_"$dim_y".log
done
make clean
~ahs3/bin/gpufree

