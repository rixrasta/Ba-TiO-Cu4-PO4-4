#!/bin/bash
#SBATCH -J separate
#SBATCH -N 1
#SBATCH --ntasks-per-node=2
#SBATCH -t 10:00:00
#SBATCH -p main

module purge
module load octave-4.2.2
octave --no-gui arguments.m 0 -2 10 9 27 26
