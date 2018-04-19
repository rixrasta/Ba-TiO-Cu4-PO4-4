'''
Created on 10. apr 2018

@author: Riho
'''
import os
c=-1
ranges = ["75 15 165 105", "75 15 -15 -75", "75 15 -105 -165", "165 105 75 15", "165 105 165 105", "165 105 -15 -75", "165 105 -105 -165"]
ranges += ["15 0 180 0", "15 0 0 -180", "105 75 180 0", "105 75 0 -180", "180 165 180 0", "180 165 0 -180"]
#print(ranges)
for bg in range(0,40,4):
    #print(bg)
    c+=1
    for s in [1,3,4]:
        i=0
        f= open("script"+str(i+1)+"_"+str(c)+".sh","w+")
        f.write("#!/bin/bash \n")
        f.write("#SBATCH -J separate \n")
        f.write("#SBATCH -N 1 \n")
        f.write("#SBATCH --ntasks-per-node=2 \n")
        f.write("#SBATCH -t 4:00:00 \n")
        f.write("#SBATCH -p main \n")
        if s==4 and bg==36:
            f.write("#SBATCH --mail-type=END \n")
            f.write("#SBATCH --mail-user=riho92@ut.ee \n")
        f.write("\n")
        f.write("module purge \n")
        f.write("module load octave-4.2.2 \n")
        f.write("octave --no-gui arguments_b.m "+str(s)+" "+str(20-bg)+" "+str(16-bg)+" 10 -10 20 -20")
        f.close() 

        os.system("sbatch script"+str(i+1)+"_"+str(c)+".sh")
    

