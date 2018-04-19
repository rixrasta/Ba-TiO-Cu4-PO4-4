#!/bin/bash
#SBATCH -J separate
#SBATCH -N 1
#SBATCH --ntasks-per-node=2
#SBATCH -t 01:05:10
#SBATCH -p testing

module purge
module load python-3.6.3
python script_runner.py
