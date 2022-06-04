#!/usr/bin/env python3
import os
from math import cos,sin,sqrt
from random import gauss,randint
from numpy import linspace

bruit = 2
cycle = 15
frequence = 30
taille = 720
tlen = 80
tmax = 20
tendance1,tendance2 = [],[]
sign = 1
while len(tendance1) <= taille:
    tendance1 += list(linspace(tmax*(4+sign),tmax*(4-sign),tlen+randint(0,tlen/2)))
    sign = -sign
tendance1 = tendance1[:taille+1]
while len(tendance2) <= taille:
    tendance2 += list(linspace(tmax*(4+sign),tmax*(4-sign),tlen+randint(0,tlen/2)))
    sign = -sign
tendance2 = tendance2[:taille+1]

gen1 = [sin(frequence*i/taille)*cycle+gauss(0,1)*bruit+tendance1[i] for i in range(taille)]
gen1.insert(0,0)
gen2 = [cos(frequence*i/taille)*cycle+gauss(0,1)*bruit+tendance2[i] for i in range(taille)]
gen2.insert(0,0)

f = open("training_set-template.csv","r")
g = open("training_set-new_set.csv","w")
for (i,ligne) in enumerate(f):
    if len(ligne)<2 or ligne[0] == 'p':
        g.write(ligne)
    else:
        data = ligne.split(",")
        if i in range(1,taille+1):
            nvals = [gen1[i],gen1[i]*0.95,gen1[i]*(1-gauss(0.025,0.005)),gen1[i]*(1-gauss(0.025,0.005))]
        if i in range(taille+1,2*taille+1):
            nvals = [gen2[i-taille],gen2[i-taille]*0.95,gen2[i-taille]*(1-gauss(0.025,0.005)),gen2[i-taille]*(1-gauss(0.025,0.005))]
        if i > 2*taille:
            nvals = [gen2[i-2*taille]/gen1[i-2*taille],gen2[i-2*taille]/gen1[i-2*taille],gen2[i-2*taille]/gen1[i-2*taille]*(1-gauss(0.025,0.005)),gen2[i-2*taille]/gen1[i-2*taille]*(1-gauss(0.025,0.005))]
        g.write(data[0]+","+data[1]+",")
        g.write(",".join([str(x) for x in nvals]))
        g.write(","+data[6])
f.close()
g.close()

from matplotlib import pyplot as plt
x = linspace(1,taille,taille)
plt.plot(x,gen1[1:])
plt.plot(x,gen2[1:])
plt.show()
