#! /bin/sh


# run experiment for Threads = {1,2,4,6, 8,10,12,14,16,20,24}.
export OMP_NUM_THREADS=1
gcc -fopenmp q2.c
./a.out






