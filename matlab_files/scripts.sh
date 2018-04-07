#!/bin/bash
#SBATCH -J separate
#SBATCH -N 1
#SBATCH --ntasks-per-node=2
#SBATCH -t 00:01:10
#SBATCH -p testing

module purge
module load Octave-4.2.2
matlab -nodisplay < gonio12_optimum.m
