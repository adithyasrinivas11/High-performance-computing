#! /bin/sh

# run experiment for Threads = {1,2,4,6, 8,10,12,14,16,20,24}.
export OMP_NUM_THREADS=24
gcc -fopenmp q22.c
./a.out




