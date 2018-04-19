'''
Created on 10. apr 2018

@author: Riho
'''
import os
c=-1
ranges = ["55 35 75 15" "55 35 165 105", "55 35 -15 -75", "55 35 -105 -165", "145 125 75 15", "145 125 165 105", "145 125 -15 -75", "145 125 -105 -165"]
#ranges += ["15 0 180 0", "15 0 0 -180", "105 75 180 0", "105 75 0 #%-180", "180 165 180 0", "180 165 0 -180"]
print(ranges)
for bg in ranges:
    print(bg)
    c+=1
    for i in range(90,-91,-4):
        f= open("script"+str(i+1)+"_"+str(c)+".sh","w+")
        f.write("#!/bin/bash \n")
        f.write("#SBATCH -J separate \n")
        f.write("#SBATCH -N 1 \n")
        f.write("#SBATCH --ntasks-per-node=2 \n")
        f.write("#SBATCH -t 10:00:00 \n")
        f.write("#SBATCH -p main \n")
        if i == -86 & c == 7:
            f.write("#SBATCH --mail-type=END \n")
            f.write("#SBATCH --mail-user=riho92@ut.ee \n")
        f.write("\n")
        f.write("module purge \n")
        f.write("module load octave-4.2.2 \n")
        f.write("octave --no-gui arguments.m "+str(i)+" "+str(i-3)+" "+bg)
        f.close() 

        os.system("sbatch script"+str(i)+"_"+str(c)+".sh")
		os.remove("sbatch script"+str(i)+"_"+str(c)+".sh")
    

