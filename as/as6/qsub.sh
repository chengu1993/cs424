#!/bin/sh

qsub -I -l procs=5,tpn=5,mem=40gb,walltime=4:00:00 -q cpsc424gpu
