# Chen GU Assignment 3 CPSC 424
## Building and running information
### Development environment
#### Module loaded
```
[cg736@compute-33-1 task2]$ module list
Currently Loaded Modulefiles:
  1) Base/yale_hpc               2) Langs/Intel/15              3) MPI/OpenMPI/1.8.6-intel15
```
#### env command
```
[cg736@compute-33-1 task2]$ env
MKLROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl
MANPATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/share/man:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/man/en_US:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/man/:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/man/:/usr/share/man:/opt/moab/share/man:
GDB_HOST=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin/gdb-ia-mic
HOSTNAME=compute-33-1.local
IPPROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp
INTEL_LICENSE_FILE=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/licenses:/opt/intel/licenses:/home/apps/fas/Licenses/intel_site.lic
TERM=xterm-256color
SHELL=/bin/bash
HISTSIZE=1000
GDBSERVER_MIC=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/target/mic/bin/gdbserver
SSH_CLIENT=10.191.63.252 58237 22
LIBRARY_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/../compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/intel64/gcc4.4
PERL5LIB=/opt/moab/lib/perl5
FPATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include
QTDIR=/usr/lib64/qt-3.3
QTINC=/usr/lib64/qt-3.3/include
MIC_LD_LIBRARY_PATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/mic:/opt/intel/mic/coi/device-linux-release/lib:/opt/intel/mic/myo/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/mic
SSH_TTY=/dev/pts/20
ANT_HOME=/opt/rocks
USER=cg736
LD_LIBRARY_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/../compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/tools/intel64/perfsys:/opt/intel/mic/coi/host-linux-release/lib:/opt/intel/mic/myo/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/intel64/gcc4.4:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/ipt/intel64/lib
MIC_LIBRARY_PATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/mic
ROCKS_ROOT=/opt/rocks
CPATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/include
YHPC_COMPILER=Intel
OMPI_MCA_orte_precondition_transports=f20cd2d28f432704-15e3f8c3bb8e89d6
NLSPATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/locale/%l_%t/%N
MAIL=/var/spool/mail/cg736
PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/bin:/home/apps/fas/Modules:/usr/lib64/qt-3.3/bin:/opt/moab/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/usr/java/latest/bin:/opt/rocks/bin:/opt/rocks/sbin:/home/apps/bin:/home/fas/cpsc424/cg736/bin
YHPC_COMPILER_MINOR=164
TBBROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb
C_INCLUDE_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include
F90=ifort
PWD=/home/fas/cpsc424/cg736/as/as3/task2
_LMFILES_=/home/apps/fas/Modules/Base/yale_hpc:/home/apps/fas/Modules/Langs/Intel/15:/home/apps/fas/Modules/MPI/OpenMPI/1.8.6-intel15
YHPC_COMPILER_MAJOR=2
JAVA_HOME=/usr/java/latest
GDB_CROSS=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin/gdb-mic
DOMAIN=omega
LANG=en_US.iso885915
MODULEPATH=/home/apps/fas/Modules
MOABHOMEDIR=/opt/moab
YHPC_COMPILER_RELEASE=2015
LOADEDMODULES=Base/yale_hpc:Langs/Intel/15:MPI/OpenMPI/1.8.6-intel15
KDEDIRS=/usr
F77=ifort
MPM_LAUNCHER=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/mpm/bin/start_mpm.sh
CXX=icpc
SSH_ASKPASS=/usr/libexec/openssh/gnome-ssh-askpass
HISTCONTROL=ignoredups
INTEL_PYTHONHOME=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/python/intel64/
SHLVL=1
HOME=/home/fas/cpsc424/cg736
FC=ifort
LOGNAME=cg736
QTLIB=/usr/lib64/qt-3.3/lib
CVS_RSH=ssh
SSH_CONNECTION=10.191.63.252 58237 10.191.12.33 22
MODULESHOME=/usr/share/Modules
LESSOPEN=||/usr/bin/lesspipe.sh %s
arch=intel64
INFOPATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/info/:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/info/
CC=icc
DISPLAY=localhost:11.0
INCLUDE=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include
MPI_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15
G_BROKEN_FILENAMES=1
BASH_FUNC_module()=() {  eval `/usr/bin/modulecmd bash $*`
}
_=/bin/env
OLDPWD=/home/fas/cpsc424/cg736/as/as3
```
### How to run the code
The source code and scripts of different tasks are organized in sub directory `task1`, `task2`, `task3` and `task4` respectively. I achieved generalization in task4, so there will be no `task5` explicitly. 

To run the program, you can enter each sub directory and submit the job to running queue by typing:
```
qsub build-run-1node.sh
qsub build-run-2node.sh
qsub build-run-4node.sh
```
to run task in 1 node, 2 nodes and 4 nodes.
## Output and evaluation
### task 1
The timing table of task 1 is:

N | TIME (secs)
------- | -------
1000 | 0.1803
2000 | 2.2647
4000 | 19.7782
8000 | 157.3758

### task 2
First I will show the timing table in different number of nodes.

#### 1 node

**Sum of run time (seconds)**

N\process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
1000  | 0.215885 | 0.306475 | 0.450074 | 0.601574
2000  | 2.425190 | 3.044074 | 3.201798 | 3.871181
4000  | 20.018297 | 27.781472 | 40.754660 | 51.995888
8000  | 156.696647 | 216.887571 | 318.749308 | 430.594415

**Sum of calculation time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
1000  | 0.180325 | 0.181510 | 0.181630 | 0.183803
2000  | 2.293825 | 1.842267 | 1.454628 | 1.450802
4000  | 19.498338 | 19.158889 | 20.352689 | 22.637396
8000  | 154.397387 | 154.995517 | 174.747626 | 210.237270

**Sum of communication time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
1000  | 0.035560 | 0.124965 | 0.268444 | 0.417771
2000  | 0.131365 | 1.201807 | 1.747170 | 2.420380
4000  | 0.519959 | 8.622583 | 20.401971 | 29.358492
8000  | 2.299260 | 61.892054 | 144.001682 | 220.357145


**Wall time on master in all (seconds)**

N\#process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
1000  | 0.215885 | 0.153236 | 0.112514 | 0.075192
2000  | 2.425190 | 1.522035 | 0.800454 | 0.483901
4000  | 20.018297 | 13.890735 | 10.188668 | 6.499490
8000  | 156.696647 | 108.443788 | 79.687322 | 53.824303


**Run time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
1000  | 0.075782 |0.075777 |0.075781 |0.075777 |0.075782 |0.075777 |0.075781 |0.075777
2000  | 0.492074 |0.492068 |0.492075 |0.492069 |0.492075 |0.492068 |0.492075 |0.492069
4000  | 6.477182 |6.477175 |6.477182 |6.477176 |6.477182 |6.477175 |6.477182 |6.477176
8000  | 53.639250 | 53.639600 | 53.639252 | 53.639603 | 53.639319 | 53.639600 | 53.639252  | 53.639603

**Calculation time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
1000  | 0.004963 |0.012748 |0.019038 |0.023790 |0.027630 |0.030351 |0.032181 |0.033077 
2000  | 0.038482 |0.098632 |0.146372 |0.189089 |0.225180 |0.244387 |0.266633 |0.270409
4000  | 0.330335 |1.501045 |1.913409 |3.324615 |2.965752 |4.128365 |3.585741 |4.444161
8000  | 5.343690 |16.059922 |19.641841 |29.739247 |28.505883 |36.985279 |33.491720 |39.967321

**Communication time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
1000  | 0.070819 |0.063029 |0.056743 |0.051987 |0.048152 |0.045426 |0.043600 |0.042700 
2000  | 0.453592 |0.393436 |0.345703 |0.302980 |0.266896 |0.247681 |0.225442 |0.221660
4000  | 6.146847 |4.976130 |4.563774 |3.152560 |3.511430 |2.348810 |2.891441 |2.033015
8000  | 48.295560 |37.579678 |33.997411 |23.900356 |25.133435 |16.654321 |20.147532 |13.672282

#### 2 node

**Sum of run time (seconds)**

N\process | 8
--------- | -------
4000  | 38.986054 
8000  | 327.115337 

**Sum of calculation time (seconds)**

N\process | 8
--------- | -------
4000  | 14.340157 
8000  | 151.565007 

**Sum of communication time (seconds)**

N\process | 8
--------- | -------
4000  | 24.645897 
8000  | 175.550330 


**Wall time on master (seconds)**

N\process | 8
--------- | -------
4000  | 4.873260 
8000  | 40.889114 


**Run time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.873260 | 4.873252 | 4.873259 | 4.873249 | 4.873263 | 4.873254 | 4.873263 | 4.873254
8000  | 40.889114 | 40.889127 | 40.890290 | 40.890305 | 40.889115 | 40.889128 | 40.889123 | 40.889135

**Calculation time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.274690 | 0.717409 | 1.105907 | 1.558488 | 2.209476 | 2.626210 | 2.879928 | 2.968050
8000  | 2.407413 | 9.197259 | 15.224698 | 19.581344 | 23.258097 | 25.783810 | 27.688041 | 28.424343--

**Communication time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.598570 | 4.155843 | 3.767352 | 3.314761 | 2.663787 | 2.247044 | 1.993335 | 1.905204
8000  | 38.481701 | 31.691868 | 25.665592 | 21.308961 | 17.631017 | 15.105318 | 13.201082 | 12.464792

#### 4 node

**Sum of run time (seconds)**

N\process  |  8
--------- | ---------
4000  | 38.808209 
8000  | 326.889003

**Sum of calculation time (seconds)**

N\process  |  8
--------- | ---------
4000  | 14.346653
8000  | 151.519507

**Sum of communication time (seconds)**

N\process  |  8
--------- | ---------
4000  | 24.461557 
8000  | 175.369496 


**Wall time on master in all (seconds)**

N\process  |  8
--------- | ---------
4000  | 4.851024
8000  | 40.861116 

**Run time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.834240 | 4.834240 | 4.834240 | 4.834238 | 4.834243 | 4.834242 | 4.834242 | 4.834242
8000  | 40.909679 | 40.909693 | 40.909686 | 40.909700 | 40.909677 | 40.909691 | 40.909687 | 40.909700
**Calculation time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.274826 | 0.717464 | 1.112987 | 1.573690 | 2.179168 | 2.638708 | 2.886416 | 2.948114
8000  | 2.390041 | 9.159568 | 15.245518 | 19.592423 | 23.271797 | 25.822184 | 27.655274 | 28.372152

**Communication time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | ----- 
4000  | 4.559414 | 4.116776 | 3.721253 | 3.260548 | 2.655075 | 2.195534 | 1.947826 | 1.886128
8000  | 38.519638 | 31.750125 | 25.664168 | 21.317277 | 17.637880 | 15.087507 | 13.254413 | 12.537548



**Performance Discussion**
We can see that with number of nodes and number of processors increasing, the performance is getting better. If fix the size of task to be 8000 and number of nodes to be 1, from the tables above, we can see that it takes 156.696647 seconds for a single process to do the multiplication, which is almost the same the serial program. However, it only takes 108.443788, 79.687322 and 53.824303 seconds for program with 2, 4, and 8 processes respectively. The wall time needed decreases when the number of processes increases. The following speedup table better illustrates the performance gain. (This table uses data with `#nodes=1`)

p    | speedup 
---- | ------
1    | 	1.00
2    |	1.45	
4    |	1.97
8    |	2.92


**Scalability discussion**
Since in task2 we use blocking method, the communication overhead is huge especially when there are multiple processes. The tables shows that the overall time spent on communication is more than the time spent on calculation when `p=8` and `#node=2`. It takes about 40 seconds with 2 nodes and 8 processors. When I increase the number of nodes to be 4 and fix the number of processors to be 8, it still need approximately 40 seconds. This demonstrates that now communication overhead becomes the bottleneck the performance gain. I calculate efficiency with `#node = 1 N=8000`. The table below shows the result.

p    | efficiency
---- | ------
1    | 	1.00
2    |	0.73	
4    |	0.49
8    |	0.365

With number of processes increases, the efficiency drops significantly, when p approaches infinity, efficiency will approach 0. Task2 clearly doesn't have strong scalability. 

p    | N         | efficiency
---- | ------     | ---------
1    | 	1000		| 0.84
2    |	2000	   | 0.74
4    |	4000     | 0.48
8    |	8000     | 0.365


With `p` and `N` increase at same speed, the efficiency still declines. Task2 may achieve weak scalability with a high N to p increase ratio. Overall, using blocking method does not scale well.

**Load Balance discussion**
The load balance is terrible because we give each process unbalanced amount of work. Let's see an example. If `N=6` and there are 3 processes. Each process will get 2-row block. Process 0 will get 3 elements while process 2 will get 11 elements.

```
x
x x

...
x x x x x
x x x x x x
```

Each process will use these row block to calculate partial result throughout the whole process and it is not fair. And it's the same for column block. In each iteration, each process will get different number of elements. The process with light workload will just sit there and waiting while others with heavy workload is doing most calculations. This is proven by the result, in the table **Calculation time of different processes with node = 4 and = 8**, when `N=8000`, process 0 work only for 2.39 seconds while process 7 works for 28.37 seconds. The table shows the how many elements each process is assigned. We can see that the load is extremely unbalanced.

0  | 1 | 2| 3| 4| 5 | 6 | 7
---|---|--|--|--|---|---|---
500500 |1500500 |2500500| 3500500 |4500500 |5500500 |6500500 |7500500


**Suggestion**
1. We can use non-blocking method rather than blocking method. Thus we can overlay communication and computation. And the expectation by doing so is that we can reduce wall time required to perform the multiplication.
2. We can split the work more evenly, so that we can achieve better load balancing. One solution would be assign the block based on the number of elements rather than number of rows. The expectation by doing so is that each process can work for nearly same amount of time.
3. If we adopt previous two methods, the scalability will be improved significantly. Since the communication overhead introduced by adding more processors are now overplayed by computation and computation are more balanced, we can achieve better performance when adding more computing resources.

**Conclusion**
Comparing the table with `P = 8` we can see that when number of nodes increases from 1 to 2, the overall wall time decreases by 8 seconds. But when number of nodes goes from 2 to 4, we cannot see any performance gain. It may be restrained by blocking communication and unbalanced workload.

### task 3

We can overlay computation and communication in order to have better performance. In each iteration, we can first use non-blocking send and receive to send and receive data, followed by calculation. But to support that, we need to use 2 buffers to send and receive data simultaneously. The pseudo code looks like following:
```
	buffer1, buffer2;
	for(int i=0; i<size; i++){
		//non blocking send using buffer1
		//non blocking receive using buffer2
		//calculation;
		//swap buffer1 and buffer2
	}
```


#### 1 node

**Sum of run time (seconds)**

N\process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
4000  | 19.511368 | 26.903194 | 39.570196 | 47.681605
8000  | 154.651165 | 214.007184 | 318.885342 | 402.790415

**Sum of calculation time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
4000  | 19.448634 | 19.184422 | 20.755363 | 24.934153
8000  | 154.412760 | 155.041986 | 177.776433 | 226.791586

**Sum of communication time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
4000  | 0.062734 | 7.718772 | 18.814833 | 22.747452
8000  | 0.238405 | 58.965198 | 141.108909 | 175.998830


**Wall time on master in all (seconds)**

N\#process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
4000  | 19.511368 | 13.451597 | 9.892548 | 5.960212
8000  | 154.651165 | 107.0035928 | 79.721335 | 50.348802


**Run time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 5.960212 | 5.960190 | 5.960209 | 5.960193 | 5.960213 | 5.960190 | 5.960207 | 5.960192
8000  | 50.348802 | 50.348804 | 50.348797 | 50.348805 | 50.348801 | 50.348804 | 50.348797 | 50.348805

**Calculation time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.403713 | 1.884659 | 2.299092 | 3.610072 | 3.427107 | 4.512747 | 3.954035 | 4.842727
8000  | 6.297138 | 17.969836 | 21.775928 | 32.747183 | 31.339777 | 38.457060 | 35.317988 | 42.886676

**Communication time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 5.556499 | 4.075531 | 3.661117 | 2.350121 | 2.533106 | 1.447443 | 2.006172 | 1.117465
8000  | 44.051664 | 32.378968 | 28.572869 | 17.601622 | 19.009024 | 11.891744 | 15.030809 | 7.462129

#### 2 node

**Sum of run time (seconds)**

N\process | 8
--------- | -------
4000  | 35.731653 
8000  | 304.465445 

**Sum of calculation time (seconds)**

N\process | 8
--------- | -------
4000  | 17.742337 
8000  | 175.048904 

**Sum of communication time (seconds)**

N\process | 8
--------- | -------
4000  | 17.989316 
8000  | 129.416540 


**Wall time on master (seconds)**

N\process | 8
--------- | -------
4000  | 4.466458 
8000  | 38.058177 


**Run time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.466458 | 4.466458 | 4.466454 | 4.466458 | 4.466457 | 4.466456 | 4.466454 | 4.466457
8000  | 38.058177 | 38.058181 | 38.058177 | 38.058181 | 38.058180 | 38.058184 | 38.058181 | 38.058184

**Calculation time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.275102 | 0.758431 | 1.122159 | 1.678776 | 2.989252 | 3.644583 | 3.429223 | 3.844810
8000  | 3.310198 | 10.721182 | 15.598748 | 20.754223 | 27.493846 | 31.306489 | 31.996944 | 33.867274

**Communication time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.191356 | 3.708027 | 3.344295 | 2.787682 | 1.477205 | 0.821874 | 1.037231 | 0.621647
8000  | 34.747979 | 27.336998 | 22.459429 | 17.303957 | 10.564334 | 6.751695 | 6.061237 | 4.190910

#### 4 node

**Sum of run time (seconds)**

N\process  |  8
--------- | ---------
4000  | 30.713541 
8000  | 265.287153

**Sum of calculation time (seconds)**

N\process  |  8
--------- | ---------
4000  | 14.347817
8000  | 151.678206

**Sum of communication time (seconds)**

N\process  |  8
--------- | ---------
4000  | 16.365724 
8000  | 113.608947 


**Wall time on master in all (seconds)**

N\process  |  8
--------- | ---------
4000  | 3.839191
8000  | 33.160886 

**Run time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 3.839191 | 3.839193 | 3.839192 | 3.839194 | 3.839192 | 3.839194 | 3.839192 | 3.839193
8000  |33.160886 | 33.160891 | 33.160894 | 33.160897 | 33.160892 | 33.160897 | 33.160896 | 33.160900
**Calculation time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.274826 | 0.716101 | 1.123325 | 1.578339 | 2.182287 | 2.619420 | 2.891537 | 2.961982
8000  | 2.399635 | 9.184794 | 15.245746 | 19.581521 | 23.288280 | 25.796413 | 27.802450 | 28.379367

**Communication time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | ----- 
4000  | 3.564365 | 3.123092 | 2.715867 | 2.260855 | 1.656905 | 1.219774 | 0.947655 | 0.877211
8000  | 30.761251 | 23.976097 | 17.915148 | 13.579376 | 9.872612 | 7.364484 | 5.358445 | 4.781533

**Difference between task 2 in performance and explanation**
When `N=8000, p=8`, the wall time needed by task 2 is 53, 40 and 40 seconds when there are 1, 2 and 4 nodes respectively. As a comparison, the wall time needed by task 3 is 50, 38 and 33 seconds. In task2, more time is spent on communication while in task 3, more time is spent on calculation. The performance gain may not seem substantial at first look, but `8000` is still a relative small scale, if `N` is much larger, then the improvement in performance will be more significant.

The table below gives a sense how the speedup of task 3 looks like compared with that of task 2. (with `p=8, #node = 4`)

N    | speedup in task2 | speedup in task3
---- | ------           | ------
4000    |	4.07				 | 5.16
8000    |	3.85					| 4.74



**Difference between task 2 in scalability and explanation**
The scalability of task 3 is slightly better than task 2 because by using non-blocking message passing, process with heavy workload does not wail util it finishes its calculation to send and receive B block. The communication overhead is now offset by the overlay of communication and computation. In task 2, the total communication cost is 175 seconds when `p=8, node=4, N=8000`, but in task 3, it is merely 113 seconds. With smaller communication overhead, program works faster when N is huge and scales better when there are multiple processors and nodes. The table below gives a comparison between task 2 and task 3 in terms of scalability. (with `#node = 4, N = 8000`). We can see that the efficiency improves by 10 percent in such setting. The overall scalability is improved, though it is still weak scalability.

p    | efficiency in task 2 | efficiency in task 3
---- | ------ | ---------
8    |	0.49  | 0.59



**Difference between task 2 in load balance and explanation**
The table **Calculation time of different processes with node = 4 and p 8** illustrates that the uneven workload problem still exists in task 3. Process 0 only works for 2.39 seconds while process 7 works for 28.37 seconds. This is because the master adopts the same distribution strategy. Using non-blocking message passing method cannot address that problem. We need a better strategy in terms of workload distribution. The element distribution table is the same task 2.

0  | 1 | 2| 3| 4| 5 | 6 | 7
---|---|--|--|--|---|---|---
500500 |1500500 |2500500| 3500500 |4500500 |5500500 |6500500 |7500500

### task 4
As discussed in task2, the reason why the load balancing works not very well is because the master does not split the work evenly. Here I came up with a very simple strategy to solve this problem. If the size of matrix is `N`, then there will be `N(N+1)/2` elements in `A` and `B`. Let's denote number of processes as `size`. Ideally, each process should get `N(N+1)/2/size` elements. We use `avg` to represent `N(N+1)/2/size` in the following discussion. The master tries to send rows to processes starting from row 0. Each process should at least get one row. Let `cur_size` denote the current number of elements master want to send to next process. If `cur_size` plus next row of elements still smaller than `avg`, the master send that row to the process until `cur_size` is lager than `avg`. For process 0 to size-2, we use this approach to send out row and column blocks. For process size-1, it will receive all remaining row and column block. Such strategy can shown in following pseudo code.
```
		avg = (N+1) * N / 2;
		for(i=0; i<size-1; i++) {
		int cur_size = row_size[idx++]; // each process at least get one row
			while(cur_size + row_size[idx] < avg){
				cur_size += row_size[idx++];
				// Send to process i
			} 
			//Send all remaining size to process size-1
		}
```
When `N` is a large number, this approach can split the workload quite evenly, though not optimal.



#### 1 node

**Sum of run time (seconds)**

N\process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
4000  | 26.231928 | 30.335556 | 38.877738 | 46.647150
8000  | 206.453949 | 239.904405 | 310.272931 | 395.472496

**Sum of calculation time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
4000  | 26.174833 | 25.923724 | 27.975264 | 32.488708
8000  | 206.213265 | 206.268777 | 225.666618 | 269.997523

**Sum of communication time (seconds)**

N\#process   | 1    |  2   |  4   | 8
----- | ---- | ---- | ---- | ----
4000  | 0.057095 | 4.411832 | 10.902474 | 14.158442
8000  | 0.240684 | 33.635628 | 84.606313 | 125.474973


**Wall time on master in all (seconds)**

N\#process   | 1    |  2   |  4   | 8
--------- | -------- | -------- | -------- | -------
4000  | 26.231928 | 15.167774 | 9.719429 | 5.830890
8000  | 206.453949 | 119.952199 | 77.568227 | 49.434058


**Run time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 5.830890 | 5.830898 | 5.830889 | 5.830897 | 5.830890 | 5.830898 | 5.830890 | 5.830897
8000  | 49.434058 | 49.434067 | 49.434057 | 49.434066 | 49.434058 | 49.434067 | 49.434057 | 49.434066

**Calculation time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 5.102436 | 4.744247 | 4.451221 | 4.143491 | 3.936015 | 3.580964 | 3.314493 | 3.215842
8000  | 44.909368 | 38.750397 | 37.398182 | 33.421127 | 32.973368 | 28.563665 | 28.135317 | 25.846099

**Communication time of different processes with node = 1 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.728455 | 1.086651 | 1.379668 | 1.687407 | 1.894875 | 2.249934 | 2.516397 | 2.615055
8000  | 4.524690 | 10.683670 | 12.035875 | 16.012939 | 16.460690 | 20.870402 | 21.298740 | 23.587967

#### 2 node

**Sum of run time (seconds)**

N\process | 8
--------- | -------
4000  | 32.220555 
8000  | 303.818205 

**Sum of calculation time (seconds)**

N\process | 8
--------- | -------
4000  | 26.120232 
8000  | 226.688834 

**Sum of communication time (seconds)**

N\process | 8
--------- | -------
4000  | 6.100323 
8000  | 77.129371 


**Wall time on master (seconds)**

N\process | 8
--------- | -------
4000  | 4.027569 
8000  | 37.977282 


**Run time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 4.027569 | 4.027573 | 4.027566 | 4.027573 | 4.027566 | 4.027572 | 4.027564 | 4.027572
8000  | 37.977282 | 37.977284 | 37.977279 | 37.977284 | 37.977269 | 37.977270 | 37.977266 | 37.977271

**Calculation time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 3.962262 | 3.831903 | 3.462439 | 3.449887 | 3.133676 | 2.868331 | 2.803538 | 2.608196
8000  | 37.601675 | 33.587441 | 31.370342 | 28.822635 | 26.228431 | 24.142901 | 23.288236 | 21.647173

**Communication time of different processes with node = 2 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 0.065307 | 0.195670 | 0.565127 | 0.577686 | 0.893890 | 1.159241 | 1.224026 | 1.419376
8000  |  0.375607 | 4.389843 | 6.606937 | 9.154649 | 11.748838 | 13.834369 | 14.689030 | 16.330098

#### 4 node

**Sum of run time (seconds)**

N\process  |  8
--------- | ---------
4000  | 28.987832 
8000  | 269.094924

**Sum of calculation time (seconds)**

N\process  |  8
--------- | ---------
4000  | 21.912072
8000  | 204.597468

**Sum of communication time (seconds)**

N\process  |  8
--------- | ---------
4000  | 7.075759 
8000  | 64.497457 


**Wall time on master in all (seconds)**

N\process  |  8
--------- | ---------
4000  | 3.623479
8000  | 33.636869 

**Run time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 3.623479 | 3.623481 | 3.623479 | 3.623478 | 3.623480 | 3.623479 | 3.623479 | 3.623476
8000  | 33.636869 | 33.636868 | 33.636865 | 33.636864 | 33.636866 | 33.636866 | 33.636863 | 33.636863
**Calculation time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | -----
4000  | 3.559544 | 3.167283 | 2.944582 | 2.758816 | 2.627346 | 2.409321 | 2.286883 | 2.158297
8000  | 33.375091 | 30.251535 | 27.861630 | 25.750242 | 24.032025 | 22.424529 | 21.080940 | 19.821476

**Communication time of different processes with node = 4 and p = 8**

N\rank   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | ----- 
4000  | 0.063936 | 0.456198 | 0.678897 | 0.864661 | 0.996134 | 1.214158 | 1.336596 | 1.465179
8000  | 0.261778 | 3.385333 | 5.775235 | 7.886622 | 9.604841 | 11.212337 | 12.555923 | 13.815387

**Discussion**
From the table **Calculation time of different processes with node = 4, and = 8**, we can see that instead of having process 0 always waiting and process size-1 doing a lot of work. Now all processes work for at least twenty seconds. The solution is not the optimal solution since it still does not split the workload very evenly. It will balance the work load better when `N` is larger. We compare the element distribution between task4 and task3 and the table below shows the result. It is clear that after load balancing, each process gets about same amount of data to process.

task\rank | 0  | 1 | 2| 3| 4| 5 | 6 | 7
----------|---|---|--|--|--|---|---|---
task 3 | 500500 |1500500 |2500500| 3500500 |4500500 |5500500 |6500500 |7500500
task 4 |4000206 |3997794 |3999651 |4000345 |3995330 |3994875 |3998220 |4017579


### task 5

Anther benefits of this strategy describe in previous section is that we achieve generalization in the mean time. Now workload split has nothing to do with fixed sized blocks. Each process can have various-sized block (at least have one). The last process will handle all the remaining rows and columns. So no matter what the `N` and `p` is (as long as they are positive number), my program can work correctly.



I use following method to demonstrate the correctness of my program. Now, `N=7633` and `p=7`, and I use 4 nodes. I let my program output the whole C matrix to a file called `task5.log`. And I use serial program to output the C matrix to a file called `std.log`. Then I use command 
```
diff task5.log std.log
```
The result of this command is:
```
18936559c18936559
< 618.987898
---
> 618.987899
19338489c19338489
< 642.263684
---
> 642.263685
22231256c22231256
< 738.670571
---
> 738.670572
23201578c23201578
< 770.111782
---
> 770.111783
24257402c24257402
< 769.282856
---
> 769.282857
27583428c27583428
< 861.596650
---
> 861.596651
27939072c27939072
< 574.501568
---
> 574.501569
28050267c28050267
< 926.742288
---
> 926.742287
28215012c28215012
< 871.170011
---
> 871.170010
29378600c29378600
< 995.896688
---
> 995.896689
29566760c29566760
< 952.189416
---
> 952.189415
35001034c35001034
< 941.607205
---
> 941.607204
35848857c35848857
< 1072.661050
---
> 1072.661051
36625031c36625031
< 467.012975
---
> 467.012976
36880232c36880232
< 1188.198905
---
> 1188.198904
37817606c37817606
< 910.542771
---
> 910.542770
39391356c39391356
< 1278.969563
---
> 1278.969562
40026953c40026953
< 1300.343923
---
> 1300.343922
40283269c40283269
< 989.473369
---
> 989.473368
40674559c40674559
< 1305.234870
---
> 1305.234869
42240008c42240008
< 1365.009367
---
> 1365.009366
42351734c42351734
< 949.284154
---
> 949.284153
42688079c42688079
< 1091.388255
---
> 1091.388254
45353458c45353458
< 1461.043673
---
> 1461.043672
45430272c45430272
< 1502.795320
---
> 1502.795321
46426959c46426959
< 745.462562
---
> 745.462561
47353860c47353860
< 1534.396211
---
> 1534.396210
48140134c48140134
< 1566.838903
---
> 1566.838902
49335433c49335433
< 832.605284
---
> 832.605283
49462732c49462732
< 224.174051
---
> 224.174052
50003464c50003464
< 1652.259732
---
> 1652.259733
50694140c50694140
< 836.574256
---
> 836.574255
53079614c53079614
< 1763.367547
---
> 1763.367546
53504109c53504109
< 1111.192426
---
> 1111.192427
54239663c54239663
< 1768.557799
---
> 1768.557800
55000702c55000702
< 1225.380883
---
> 1225.380884
55116121c55116121
< 1456.039546
---
> 1456.039547
55161814c55161814
< 1437.111582
---
> 1437.111581
55191046c55191046
< 1118.861466
---
> 1118.861465
55797015c55797015
< 1833.448583
---
> 1833.448584
56809468c56809468
< 1163.546110
---
> 1163.546109
56885274c56885274
< 1062.431057
---
> 1062.431058
57323612c57323612
< 1875.337650
---
> 1875.337649
```

Surprisingly, there are difference the output. But after I examine all these difference, I find that it is due to floating point decision problem. All the difference is smaller than `10^-6`. Hence it can be neglected. I guess it is due to compiler optimization that change the adding sequence of double type.







