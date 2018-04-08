#!/bin/bash
#SBATCH -J separate
#SBATCH -N 1
#SBATCH --ntasks-per-node=2
#SBATCH -t 5
#SBATCH -p testing

module purge
module load octave-4.2.2
octave --no-gui < octave.m
