# Chen GU Assignment 4 CPSC 424
## Building and running information
### Development environment
#### Module loaded
```
Currently Loaded Modulefiles:
  1) Base/yale_hpc
  2) Langs/Intel/15
  3) MPI/OpenMPI/1.8.6-intel15
  4) Tools/TotalView/8.14.1-8
```
#### env command
```
MKLROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl
MANPATH=/home/apps/fas/Tools/TotalView/toolworks/totalview.8.14.1-8/man:/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/share/man:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/man/en_US:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/man/:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/man/:/usr/share/man:/opt/moab/share/man:
GDB_HOST=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin/gdb-ia-mic
HOSTNAME=compute-32-14.local
PBS_VERSION=TORQUE-4.2.9
IPPROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp
INTEL_LICENSE_FILE=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/licenses:/opt/intel/licenses:/home/apps/fas/Licenses/intel_site.lic
TERM=xterm-256color
SHELL=/bin/bash
HISTSIZE=1000
GDBSERVER_MIC=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/target/mic/bin/gdbserver
PBS_JOBNAME=STDIN
LIBRARY_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/../compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/intel64/gcc4.4
PERL5LIB=/opt/moab/lib/perl5
FPATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include
PBS_ENVIRONMENT=PBS_INTERACTIVE
QTDIR=/usr/lib64/qt-3.3
QTINC=/usr/lib64/qt-3.3/include
MIC_LD_LIBRARY_PATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/mic:/opt/intel/mic/coi/device-linux-release/lib:/opt/intel/mic/myo/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/mic
PBS_O_WORKDIR=/lustre/home/client/fas/cpsc424/cg736
ANT_HOME=/opt/rocks
LC_ALL=en_US
PBS_TASKNUM=1
USER=cg736
LD_LIBRARY_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/../compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/tools/intel64/perfsys:/opt/intel/mic/coi/host-linux-release/lib:/opt/intel/mic/myo/lib:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/intel64/gcc4.4:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/ipt/intel64/lib
PBS_O_HOME=/home/fas/cpsc424/cg736
MIC_LIBRARY_PATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/lib/mic:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/lib/mic
ROCKS_ROOT=/opt/rocks
CPATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb/include
PBS_WALLTIME=1800
PBS_GPUFILE=/var/spool/torque/aux//5436955.rocks.omega.hpc.yale.internalgpu
PBS_MOMPORT=15003
PBS_O_QUEUE=cpsc424
YHPC_COMPILER=Intel
OMPI_MCA_orte_precondition_transports=f20cd2d28f432704-15e3f8c3bb8e89d6
NLSPATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/compiler/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/ipp/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/lib/intel64/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/locale/%l_%t/%N:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/locale/%l_%t/%N
MAIL=/var/spool/mail/cg736
PBS_O_LOGNAME=cg736
PATH=/home/apps/fas/Tools/TotalView/toolworks/totalview.8.14.1-8/bin:/home/apps/fas/Tools/TotalView/toolworks/memoryscape.3.6.1-8/bin:/home/apps/fas/Tools/TotalView:/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/bin:/home/apps/fas/Modules:/usr/lib64/qt-3.3/bin:/opt/moab/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/usr/java/latest/bin:/opt/rocks/bin:/opt/rocks/sbin:/home/apps/bin:/home/fas/cpsc424/cg736/bin
YHPC_COMPILER_MINOR=164
PBS_O_LANG=en_US.iso885915
PBS_JOBCOOKIE=B00CD7EA66C9A03486F801149B353642
TBBROOT=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/tbb
C_INCLUDE_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/include
F90=ifort
PWD=/home/fas/cpsc424/cg736
_LMFILES_=/home/apps/fas/Modules/Base/yale_hpc:/home/apps/fas/Modules/Langs/Intel/15:/home/apps/fas/Modules/MPI/OpenMPI/1.8.6-intel15:/home/apps/fas/Modules/Tools/TotalView/8.14.1-8
YHPC_COMPILER_MAJOR=2
JAVA_HOME=/usr/java/latest
GDB_CROSS=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin/gdb-mic
DOMAIN=omega
PBS_NODENUM=0
LANG=C
MODULEPATH=/home/apps/fas/Modules
MOABHOMEDIR=/opt/moab
YHPC_COMPILER_RELEASE=2015
LOADEDMODULES=Base/yale_hpc:Langs/Intel/15:MPI/OpenMPI/1.8.6-intel15:Tools/TotalView/8.14.1-8
KDEDIRS=/usr
PBS_NUM_NODES=1
F77=ifort
PBS_O_SHELL=/bin/bash
LM_LICENSE_FILE=/home/apps/fas/Tools/TotalView/license.dat
PBS_JOBID=5436955.rocks.omega.hpc.yale.internal
MPM_LAUNCHER=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/mpm/bin/start_mpm.sh
CXX=icpc
SSH_ASKPASS=/usr/libexec/openssh/gnome-ssh-askpass
HISTCONTROL=ignoredups
INTEL_PYTHONHOME=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/python/intel64/
SHLVL=1
HOME=/home/fas/cpsc424/cg736
PBS_O_HOST=compute-33-1.local
FC=ifort
PBS_VNODENUM=0
LOGNAME=cg736
QTLIB=/usr/lib64/qt-3.3/lib
CVS_RSH=ssh
PBS_QUEUE=cpsc424
MODULESHOME=/usr/share/Modules
LESSOPEN=||/usr/bin/lesspipe.sh %s
PBS_MICFILE=/var/spool/torque/aux//5436955.rocks.omega.hpc.yale.internalmic
PBS_O_MAIL=/var/spool/mail/cg736
arch=intel64
INFOPATH=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/share/info/:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/share/info/
CC=icc
PBS_NP=8
PBS_NUM_PPN=1
PBS_O_SERVER=rocks.omega.hpc.yale.internal
INCLUDE=/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mkl/include
MPI_PATH=/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15
G_BROKEN_FILENAMES=1
PBS_NODEFILE=/var/spool/torque/aux//5436955.rocks.omega.hpc.yale.internal
PBS_O_PATH=/home/apps/fas/Tools/TotalView/toolworks/totalview.8.14.1-8/bin:/home/apps/fas/Tools/TotalView/toolworks/memoryscape.3.6.1-8/bin:/home/apps/fas/Tools/TotalView:/usr/local/cluster/hpc/MPI/OpenMPI/1.8.6-intel15/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/mpirt/bin/intel64:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64_mic/bin:/home/apps/fas/Langs/Intel/2015_update2/composer_xe_2015.2.164/debugger/gdb/intel64/bin:/home/apps/fas/Modules:/usr/lib64/qt-3.3/bin:/opt/moab/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/usr/java/latest/bin:/opt/rocks/bin:/opt/rocks/sbin:/home/apps/bin:/home/fas/cpsc424/cg736/bin
BASH_FUNC_module()=() {  eval `/usr/bin/modulecmd bash $*`
}
_=/bin/env
```
### How to run the code
I wrote a bash script that can build and run the code automatically. To do so, simply type
```
qsub build_run.sh
```

### Output
#### Output for task1
**Performance**
The following table shows the wall clock timing for actual data sets (in seconds).

actualedata1 | actualdata2 | actualdata3 | actualdata4
------- | ------- | ------- | ------- 
3.819550 | 16.144769 | 68.937818 | 264.022366

##### Output for actualdata1
```
Initial Conditions (time = 0.0)

	Center of Mass:   (2.153875e-08, 1.148863e-09, 4.334575e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 128 (time = 4.000000)

	Center of Mass:   (-4.088525e-08, -2.401514e-08, 5.250070e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 256 (time = 8.000000)

	Center of Mass:   (-1.033092e-07, -4.917914e-08, 6.165565e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 384 (time = 12.000000)

	Center of Mass:   (-1.657332e-07, -7.434314e-08, 7.081059e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 512 (time = 16.000000)

	Center of Mass:   (-2.281572e-07, -9.950714e-08, 7.996555e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 640 (time = 20.000000)

	Center of Mass:   (-2.905812e-07, -1.246711e-07, 8.912050e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 768 (time = 24.000000)

	Center of Mass:   (-3.530052e-07, -1.498351e-07, 9.827544e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 896 (time = 28.000000)

	Center of Mass:   (-4.154292e-07, -1.749991e-07, 1.074304e-08)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 1024 (time = 32.000000)

	Center of Mass:   (-4.778533e-07, -2.001631e-07, 1.165854e-08)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)

Time for 1024 timesteps with 800 bodies: 3.819550 seconds
```
##### Output for actualdata2
```
Initial Conditions (time = 0.0)

	Center of Mass:   (-4.128124e-09, -1.835931e-10, -1.653466e-08)
	Average Velocity: (-6.789229e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 128 (time = 4.000000)

	Center of Mass:   (-6.843818e-09, -1.422610e-08, -5.569169e-09)
	Average Velocity: (-6.789225e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 256 (time = 8.000000)

	Center of Mass:   (-9.559511e-09, -2.826861e-08, 5.396319e-09)
	Average Velocity: (-6.789230e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 384 (time = 12.000000)

	Center of Mass:   (-1.227520e-08, -4.231112e-08, 1.636181e-08)
	Average Velocity: (-6.789231e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 512 (time = 16.000000)

	Center of Mass:   (-1.499090e-08, -5.635363e-08, 2.732729e-08)
	Average Velocity: (-6.789231e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 640 (time = 20.000000)

	Center of Mass:   (-1.770659e-08, -7.039614e-08, 3.829278e-08)
	Average Velocity: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 768 (time = 24.000000)

	Center of Mass:   (-2.042228e-08, -8.443865e-08, 4.925827e-08)
	Average Velocity: (-6.789231e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 896 (time = 28.000000)

	Center of Mass:   (-2.313798e-08, -9.848116e-08, 6.022375e-08)
	Average Velocity: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 1024 (time = 32.000000)

	Center of Mass:   (-2.585367e-08, -1.125237e-07, 7.118924e-08)
	Average Velocity: (-6.789231e-10, -3.510628e-09, 2.741372e-09)

Time for 1024 timesteps with 1600 bodies: 16.144769 seconds
```
##### Output for actualdata3
```
Initial Conditions (time = 0.0)

	Center of Mass:   (2.738440e-09, -8.980691e-09, -3.708599e-09)
	Average Velocity: (3.605630e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 128 (time = 4.000000)

	Center of Mass:   (4.180686e-09, 6.828971e-08, 1.087360e-08)
	Average Velocity: (3.605628e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 256 (time = 8.000000)

	Center of Mass:   (5.622935e-09, 1.455601e-07, 2.545580e-08)
	Average Velocity: (3.605623e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 384 (time = 12.000000)

	Center of Mass:   (7.065183e-09, 2.228305e-07, 4.003800e-08)
	Average Velocity: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 512 (time = 16.000000)

	Center of Mass:   (8.507430e-09, 3.001009e-07, 5.462021e-08)
	Average Velocity: (3.605623e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 640 (time = 20.000000)

	Center of Mass:   (9.949683e-09, 3.773713e-07, 6.920241e-08)
	Average Velocity: (3.605621e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 768 (time = 24.000000)

	Center of Mass:   (1.139193e-08, 4.546417e-07, 8.378461e-08)
	Average Velocity: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 896 (time = 28.000000)

	Center of Mass:   (1.283418e-08, 5.319121e-07, 9.836681e-08)
	Average Velocity: (3.605621e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 1024 (time = 32.000000)

	Center of Mass:   (1.427643e-08, 6.091825e-07, 1.129490e-07)
	Average Velocity: (3.605623e-10, 1.931760e-08, 3.645550e-09)

Time for 1024 timesteps with 3200 bodies: 68.937818 seconds
```
##### Output for actualdata4
```
Initial Conditions (time = 0.0)

	Center of Mass:   (-2.018758e-08, 1.012155e-08, -3.957608e-09)
	Average Velocity: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 128 (time = 4.000000)

	Center of Mass:   (-4.234837e-08, 2.443709e-08, 2.578647e-08)
	Average Velocity: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 256 (time = 8.000000)

	Center of Mass:   (-6.450916e-08, 3.875264e-08, 5.553055e-08)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 384 (time = 12.000000)

	Center of Mass:   (-8.666995e-08, 5.306819e-08, 8.527463e-08)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 512 (time = 16.000000)

	Center of Mass:   (-1.088307e-07, 6.738374e-08, 1.150187e-07)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 640 (time = 20.000000)

	Center of Mass:   (-1.309915e-07, 8.169929e-08, 1.447628e-07)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 768 (time = 24.000000)

	Center of Mass:   (-1.531523e-07, 9.601484e-08, 1.745069e-07)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 896 (time = 28.000000)

	Center of Mass:   (-1.753131e-07, 1.103304e-07, 2.042509e-07)
	Average Velocity: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 1024 (time = 32.000000)

	Center of Mass:   (-1.974739e-07, 1.246459e-07, 2.339950e-07)
	Average Velocity: (-5.540197e-09, 3.578887e-09, 7.436020e-09)

Time for 1024 timesteps with 6400 bodies: 264.022366 seconds
```
#### Output for task2
**Performance**
The following table shows the wall clock timing for actual data sets (in seconds).

actualdata1 | actualdata2 | actualdata3 | actualdata4
---------- | ----------- | ----------- | ----------- 
1.425180 | 5.505876 | 21.939878 | 79.868258

##### Output for actualdata1
```
Initial Conditions (time = 0.0)

	#boides each octant has: (93, 98, 112, 104, 85, 107, 105, 96)
	Center of Mass:   (2.153875e-08, 1.148862e-09, 4.334575e-09)
	Average Velocity: (-1.560600e-08, -6.291000e-09, 2.288737e-10)


Conditions after timestep 128 (time = 4)

	#boides each octant has: (107, 84, 101, 109, 108, 94, 83, 114)
	Center of Mass:     (-4.088525e-08, -2.401514e-08, 5.250070e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 256 (time = 8)

	#boides each octant has: (72, 124, 135, 64, 51, 142, 149, 63)
	Center of Mass:     (-1.033092e-07, -4.917914e-08, 6.165565e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 384 (time = 12)

	#boides each octant has: (45, 135, 150, 52, 42, 158, 170, 48)
	Center of Mass:     (-1.657333e-07, -7.434314e-08, 7.081060e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 512 (time = 16)

	#boides each octant has: (36, 137, 154, 38, 37, 176, 181, 41)
	Center of Mass:     (-2.281573e-07, -9.950714e-08, 7.996555e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 640 (time = 20)

	#boides each octant has: (38, 144, 152, 33, 29, 173, 192, 39)
	Center of Mass:     (-2.905813e-07, -1.246711e-07, 8.912050e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 768 (time = 24)

	#boides each octant has: (32, 150, 171, 26, 23, 179, 186, 33)
	Center of Mass:     (-3.530053e-07, -1.498351e-07, 9.827545e-09)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 896 (time = 28)

	#boides each octant has: (31, 151, 148, 23, 22, 186, 212, 27)
	Center of Mass:     (-4.154293e-07, -1.749991e-07, 1.074304e-08)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)


Conditions after timestep 1024 (time = 32)

	#boides each octant has: (29, 140, 167, 23, 24, 199, 193, 25)
	Center of Mass:     (-4.778533e-07, -2.001631e-07, 1.165853e-08)
	Average Velocities: (-1.560600e-08, -6.291000e-09, 2.288738e-10)

Time for 1024 timesteps with 800 bodies: 1.425180 seconds
```
##### Output for actualdata2
```
Initial Conditions (time = 0.0)

	#boides each octant has: (194, 203, 188, 188, 234, 213, 188, 192)
	Center of Mass:   (-4.128125e-09, -1.835931e-10, -1.653466e-08)
	Average Velocity: (-6.789231e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 128 (time = 4)

	#boides each octant has: (238, 223, 161, 164, 197, 220, 206, 191)
	Center of Mass:     (-6.843818e-09, -1.422610e-08, -5.569169e-09)
	Average Velocities: (-6.789231e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 256 (time = 8)

	#boides each octant has: (109, 306, 268, 113, 114, 276, 300, 114)
	Center of Mass:     (-9.559510e-09, -2.826861e-08, 5.396319e-09)
	Average Velocities: (-6.789231e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 384 (time = 12)

	#boides each octant has: (90, 332, 291, 73, 73, 295, 343, 103)
	Center of Mass:     (-1.227520e-08, -4.231112e-08, 1.636181e-08)
	Average Velocities: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 512 (time = 16)

	#boides each octant has: (64, 337, 301, 71, 62, 315, 372, 78)
	Center of Mass:     (-1.499090e-08, -5.635363e-08, 2.732729e-08)
	Average Velocities: (-6.789232e-10, -3.510628e-09, 2.741372e-09)


Conditions after timestep 640 (time = 20)

	#boides each octant has: (54, 339, 315, 65, 52, 327, 374, 74)
	Center of Mass:     (-1.770659e-08, -7.039614e-08, 3.829278e-08)
	Average Velocities: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 768 (time = 24)

	#boides each octant has: (61, 339, 322, 66, 42, 335, 367, 68)
	Center of Mass:     (-2.042228e-08, -8.443865e-08, 4.925827e-08)
	Average Velocities: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 896 (time = 28)

	#boides each octant has: (56, 335, 337, 70, 52, 323, 356, 71)
	Center of Mass:     (-2.313797e-08, -9.848116e-08, 6.022376e-08)
	Average Velocities: (-6.789232e-10, -3.510627e-09, 2.741372e-09)


Conditions after timestep 1024 (time = 32)

	#boides each octant has: (73, 300, 330, 92, 75, 303, 341, 86)
	Center of Mass:     (-2.585366e-08, -1.125237e-07, 7.118924e-08)
	Average Velocities: (-6.789231e-10, -3.510627e-09, 2.741372e-09)

Time for 1024 timesteps with 1600 bodies: 5.505876 seconds
```
##### Output for actualdata3
```
Initial Conditions (time = 0.0)

	#boides each octant has: (432, 416, 368, 395, 439, 410, 355, 385)
	Center of Mass:   (2.738438e-09, -8.980691e-09, -3.708599e-09)
	Average Velocity: (3.605623e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 128 (time = 4)

	#boides each octant has: (422, 436, 397, 408, 398, 397, 364, 378)
	Center of Mass:     (4.180687e-09, 6.828971e-08, 1.087360e-08)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 256 (time = 8)

	#boides each octant has: (180, 605, 620, 215, 194, 580, 617, 189)
	Center of Mass:     (5.622936e-09, 1.455601e-07, 2.545580e-08)
	Average Velocities: (3.605623e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 384 (time = 12)

	#boides each octant has: (149, 676, 635, 145, 165, 595, 691, 144)
	Center of Mass:     (7.065185e-09, 2.228305e-07, 4.003800e-08)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 512 (time = 16)

	#boides each octant has: (113, 696, 684, 107, 125, 637, 722, 116)
	Center of Mass:     (8.507434e-09, 3.001009e-07, 5.462021e-08)
	Average Velocities: (3.605623e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 640 (time = 20)

	#boides each octant has: (90, 742, 704, 91, 101, 617, 757, 98)
	Center of Mass:     (9.949683e-09, 3.773713e-07, 6.920241e-08)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 768 (time = 24)

	#boides each octant has: (82, 757, 694, 92, 100, 602, 785, 88)
	Center of Mass:     (1.139193e-08, 4.546417e-07, 8.378461e-08)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 896 (time = 28)

	#boides each octant has: (117, 713, 685, 120, 127, 592, 746, 100)
	Center of Mass:     (1.283418e-08, 5.319121e-07, 9.836681e-08)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)


Conditions after timestep 1024 (time = 32)

	#boides each octant has: (184, 622, 650, 181, 182, 537, 698, 146)
	Center of Mass:     (1.427643e-08, 6.091825e-07, 1.129490e-07)
	Average Velocities: (3.605622e-10, 1.931760e-08, 3.645550e-09)

Time for 1024 timesteps with 3200 bodies: 21.939878 seconds
```
##### Output for actualdata4
```
Initial Conditions (time = 0.0)

	#boides each octant has: (828, 790, 769, 814, 802, 808, 809, 780)
	Center of Mass:   (-2.018758e-08, 1.012155e-08, -3.957608e-09)
	Average Velocity: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 128 (time = 4)

	#boides each octant has: (834, 889, 802, 754, 775, 775, 763, 808)
	Center of Mass:     (-4.234837e-08, 2.443709e-08, 2.578647e-08)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 256 (time = 8)

	#boides each octant has: (400, 1219, 1220, 398, 400, 1169, 1169, 425)
	Center of Mass:     (-6.450916e-08, 3.875264e-08, 5.553055e-08)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 384 (time = 12)

	#boides each octant has: (295, 1301, 1300, 275, 275, 1339, 1306, 309)
	Center of Mass:     (-8.666995e-08, 5.306819e-08, 8.527463e-08)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 512 (time = 16)

	#boides each octant has: (222, 1342, 1355, 210, 188, 1444, 1393, 246)
	Center of Mass:     (-1.088307e-07, 6.738374e-08, 1.150187e-07)
	Average Velocities: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 640 (time = 20)

	#boides each octant has: (195, 1364, 1337, 175, 158, 1512, 1465, 194)
	Center of Mass:     (-1.309915e-07, 8.169929e-08, 1.447628e-07)
	Average Velocities: (-5.540198e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 768 (time = 24)

	#boides each octant has: (172, 1385, 1299, 164, 158, 1526, 1520, 176)
	Center of Mass:     (-1.531523e-07, 9.601483e-08, 1.745069e-07)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 896 (time = 28)

	#boides each octant has: (184, 1410, 1273, 164, 152, 1511, 1519, 187)
	Center of Mass:     (-1.753131e-07, 1.103304e-07, 2.042509e-07)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)


Conditions after timestep 1024 (time = 32)

	#boides each octant has: (196, 1397, 1265, 182, 171, 1504, 1490, 195)
	Center of Mass:     (-1.974739e-07, 1.246459e-07, 2.339950e-07)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)

Time for 1024 timesteps with 6400 bodies: 79.868258 seconds
```

### Discussion
#### Performance
The following table shows the comparison between serial program and parallel program. It is clear that when the dataset is large, the performance of parallel program is much better than serial one.

program\dataset | actualedata1 | actualdata2 | actualdata3 | actualdata4
------- | ------- | ------- | ------- | ------- 
serial    | 3.819550 | 16.144769 | 68.937818 | 264.022366
parallel  | 1.425180 | 5.505876  | 21.939878 | 79.868258

Using the table above, we can construct speedup table.

actualedata1 | actualdata2 | actualdata3 | actualdata4
------- | ------- | ------- | ------- 
2.68    | 2.93    | 3.14    | 3.31

We can see with the scale of problem increases, the speedup increases steadily. When dataset is small, much effort is spent on communication rather than computation, the benefit of parallel computing is not obvious. When the scale of problem increase, communication time is small compared with computation time.

#### Load Balance
The load balance is quite good at the beginning because bodies scatters quite evenly in the universe. For example, we can take a look at the initial conditions of actualdata4. We can see process0 has 828 bodies, 1 has 790, 2 has 769... every octant has almost the same number of bodies. 
```
Initial Conditions for actualdata4 (time = 0.0)

	#boides each octant has: (828, 790, 769, 814, 802, 808, 809, 780)
	Center of Mass:   (-2.018758e-08, 1.012155e-08, -3.957608e-09)
	Average Velocity: (-5.540198e-09, 3.578887e-09, 7.436020e-09)
```
But the load balance degrades when time goes on. At the last times step of actualdata4, we can see that octant1 only has 196 bodies, while octant 5 has 1504 bodies. My guess is that some large mass bodies will drag other light bodies towards them, which result in a situation that large body is surrounded by many small bodies. This situation will lead to many bodies residing in one octant, while some other octants only have a few bodies because they doesn't have large bodies to drag other bodies.
```
Conditions after timestep 1024 for dataset4 (time = 32)

	#boides each octant has: (196, 1397, 1265, 182, 171, 1504, 1490, 195)
	Center of Mass:     (-1.974739e-07, 1.246459e-07, 2.339950e-07)
	Average Velocities: (-5.540197e-09, 3.578887e-09, 7.436020e-09)

Time for 1024 timesteps with 6400 bodies: 79.868258 seconds
```


