'''
Created on 10. apr 2018

@author: Riho
'''
import os
for i in range(40):
    f= open("script"+str(i+1)+".sh","w+")
    f.write("#!/bin/bash \n")
    f.write("#SBATCH -J separate \n")
    f.write("#SBATCH -N 1 \n")
    f.write("#SBATCH --ntasks-per-node=2 \n")
    f.write("#SBATCH -t 10:00:00 \n")
    f.write("#SBATCH -p main \n")
    f.write("\n")
    f.write("module purge \n")
    f.write("module load octave-4.2.2 \n")
    f.write("octave --no-gui arguments.m "+str(20-i)+" "+str(19-i)+" 10 9 27 26")
    f.close() 

    os.system("sbatch script"+str(i+1)+".sh")
    

