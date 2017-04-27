# Chen GU Assignment 5 CPSC 424
## Building and running information
### Development environment
#### Module loaded
```
Currently Loaded Modulefiles:
  1) Base/yale_hpc               2) Langs/Intel/15              3) MPI/OpenMPI/1.8.6-intel15
```
#### env command
```
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
Task0, task1, task2, task3 and task4 are organized in its corresponding subdirectories. Inside each subdirectory, I provide a makefile. You can compile the file using `make` command. 
Then you can type following command to execute the program. (N is the number of bodies, and #threads is the number of threads)
```
./nbody# <N> <#threads>
``` 

Note that in task3 and task4 I provide a bash script to run the program. You can run the script by 
```
./exec.sh
```

## Output and evaluation
### Task0 Baseline Performance 
#### -O0 
```
Initial center of mass: (0.498714, 0.495386, 0.503522)

NBODY Version 00

Propagating 16384 bodies using 1 thread on CPU...

 Step    Time, s Interact/s  GFLOP/s
    1  1.436e+01  1.869e+07      0.4 *
    2  1.432e+01  1.875e+07      0.4 *
    3  1.431e+01  1.875e+07      0.4 *
    4  1.431e+01  1.876e+07      0.4
    5  1.431e+01  1.875e+07      0.4
    6  1.431e+01  1.876e+07      0.4
    7  1.431e+01  1.875e+07      0.4
    8  1.431e+01  1.875e+07      0.4
    9  1.431e+01  1.875e+07      0.4
   10  1.431e+01  1.876e+07      0.4
-----------------------------------------------------
Average performance:             0.4 +- 0.0 GFLOP/s
-----------------------------------------------------
* - warm-up, not included in average

Final center of mass: (0.548779, 0.545434, 0.553553)
```
#### -O3
```
Initial center of mass: (0.498713, 0.495385, 0.503523)

NBODY Version 00

Propagating 16384 bodies using 1 thread on CPU...

 Step    Time, s Interact/s  GFLOP/s
    1  1.444e+00  1.858e+08      3.7 *
    2  1.445e+00  1.858e+08      3.7 *
    3  1.444e+00  1.858e+08      3.7 *
    4  1.445e+00  1.857e+08      3.7
    5  1.445e+00  1.857e+08      3.7
    6  1.445e+00  1.858e+08      3.7
    7  1.445e+00  1.858e+08      3.7
    8  1.444e+00  1.858e+08      3.7
    9  1.445e+00  1.858e+08      3.7
   10  1.445e+00  1.858e+08      3.7
-----------------------------------------------------
Average performance:             3.7 +- 0.0 GFLOP/s
-----------------------------------------------------
* - warm-up, not included in average

Final center of mass: (0.548778, 0.545435, 0.553554)
```
### Task1
```
Initial center of mass: (0.498713, 0.495385, 0.503523)

NBODY Version 01

Propagating 16384 bodies using 1 thread on CPU...

 Step    Time, s Interact/s  GFLOP/s
    1  5.469e-01  4.908e+08      9.8 *
    2  5.468e-01  4.909e+08      9.8 *
    3  5.468e-01  4.909e+08      9.8 *
    4  5.467e-01  4.909e+08      9.8
    5  5.469e-01  4.908e+08      9.8
    6  5.468e-01  4.909e+08      9.8
    7  5.467e-01  4.910e+08      9.8
    8  5.469e-01  4.908e+08      9.8
    9  5.467e-01  4.910e+08      9.8
   10  5.468e-01  4.909e+08      9.8
-----------------------------------------------------
Average performance:             9.8 +- 0.0 GFLOP/s
-----------------------------------------------------
* - warm-up, not included in average

Final center of mass: (0.548778, 0.545435, 0.553553)
```
### Task2

The table below shows the performance when **N = 16384** and **#cores = 1, 2, 4, 8**.

N\cores   | 1      | 2      | 4      | 8     
------- | -------   | -------   | -------   | -------   
16384   |9.8 +- 0.0|19.6 +- 0.0|39.2 +- 0.0|75.8 +- 0.7

### Task3
#### 1 thread
```
Initial center of mass: (0.498713, 0.495385, 0.503523)

NBODY Version 03

Propagating 16384 bodies using 1 thread on CPU...

 Step    Time, s Interact/s  GFLOP/s
    1  4.507e-01  5.955e+08     11.9 *
    2  4.503e-01  5.960e+08     11.9 *
    3  4.505e-01  5.959e+08     11.9 *
    4  4.504e-01  5.960e+08     11.9
    5  4.504e-01  5.959e+08     11.9
    6  4.504e-01  5.959e+08     11.9
    7  4.503e-01  5.960e+08     11.9
    8  4.504e-01  5.960e+08     11.9
    9  4.504e-01  5.959e+08     11.9
   10  4.504e-01  5.960e+08     11.9
-----------------------------------------------------
Average performance:            11.9 +- 0.0 GFLOP/s
-----------------------------------------------------
* - warm-up, not included in average

Final center of mass: (0.548778, 0.545435, 0.553553)
```
#### 8 threads
```
Initial center of mass: (0.498713, 0.495385, 0.503523)

NBODY Version 03

Propagating 16384 bodies using 8 thread on CPU...

 Step    Time, s Interact/s  GFLOP/s
    1  6.829e-02  3.931e+09     78.6 *
    2  5.645e-02  4.755e+09     95.1 *
    3  5.653e-02  4.748e+09     95.0 *
    4  5.646e-02  4.754e+09     95.1
    5  5.646e-02  4.754e+09     95.1
    6  5.653e-02  4.748e+09     95.0
    7  5.646e-02  4.754e+09     95.1
    8  5.653e-02  4.748e+09     95.0
    9  5.646e-02  4.754e+09     95.1
   10  5.653e-02  4.749e+09     95.0
-----------------------------------------------------
Average performance:            95.0 +- 0.1 GFLOP/s
-----------------------------------------------------
* - warm-up, not included in average

Final center of mass: (0.548777, 0.545434, 0.553553)
```

The table below shows the performance in GigaFLOP rate for **N = 2048, 4096, 8192, 16384 and 32768**, and **#cores = 1 and 8**.

cores\N  | 2048      | 4096      | 8192      | 16384     | 32768
------- | -------   | -------   | -------   | -------   | -------
1       |11.8 +- 0.0|11.9 +- 0.0|11.9 +- 0.0|11.9 +- 0.0|11.8 +- 0.0|
8       |48.5 +- 2.1|83.3 +- 3.6|94.7 +- 0.5|95.0 +- 0.1|93.6 +- 1.2|

### Task4
#### Choosing best tile size
I fix problem size to be **16384**, and test **tile size = 2, 4, 8, and 16** to see which gives the best performance. From the table below we can see that with **tile size = 16**, the program reaches the best performance at **90.3 GFLOPS**. I will use **tile size = 16** in the following experiment.

N\tile size  | 2      | 4      | 8      | 16
------- | -------   | -------   | -------   | -------   |
16384   |57.5 +- 0.6|70.8 +- 0.4|77.2 +- 0.2|90.3 +- 0.1|

#### Performance
The table below shows the performance comparison between task3 and task4 in GigaFLOP rate for **N = 2048, 4096, 8192, 16384 and 32768**, and **#cores = 1 and 8**.

cores\N  | 2048      | 4096      | 8192      | 16384     | 32768
------- | -------    | -------   | -------   | -------   | -------
1 (task3) |11.8 +- 0.0|11.9 +- 0.0|11.9 +- 0.0|11.9 +- 0.0|11.8 +- 0.0|
1 (task4)      |11.3 +- 0.0|11.3 +- 0.0|11.3 +- 0.0|11.3 +- 0.0|11.3 +- 0.0|
8 (task3)     |48.5 +- 2.1|83.3 +- 3.6|94.7 +- 0.5|95.0 +- 0.1|93.6 +- 1.2|
8 (task4)      |85.4 +- 0.5|89.2 +- 0.5|89.9 +- 0.2|90.0 +- 0.1|87.8 +- 0.4|


The performance with **#core = 1** is quite stable, both task3 and task4 achieve around 11 GFLOPS. When** #core = 8 and N = 16384**, both achieves the same high performance (beyond **90 GFLOPS**). But the performance of task4 has less variation depending on N compared with that of task3 





 










