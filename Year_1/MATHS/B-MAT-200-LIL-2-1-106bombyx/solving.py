#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## B-MAT-200-LIL-2-1-106bombyx-simon.auduberteau
## File description:
## solving
##

import sys
from math import *

def calcul_wgrowth_rate(n, k):
    turn = 2
    resultat = n
    cpt = 1

    print("1", "%.2f" % resultat)
    while (cpt != 100):
        resultat = k * resultat * ((1000 - resultat) / 1000)
        print("%d" % turn, "%.2f" % resultat)
        turn += 1
        cpt += 1

def calcul_wgeneration(n, i0, i1):
    turn = 1
    k = 1
    resultat = n
    cpt = 0

    while (k < 4):
        resultat = n
        while (cpt <= i0):
            resultat = k * resultat * ((1000 - resultat) / 1000)
            if cpt == i0:
                print("%.2f" % k, "%.2f" % resultat)
            cpt += 1
        cpt = 0
        while cpt != i1 - i0:
            print("%.2f" % k, "%.2f" % resultat)
            resultat = k * resultat * ((1000 - resultat) / 1000)
            cpt += 1
        k += 0.01
        cpt = 0


def calcul():
    n = int(sys.argv[1])
    if (len(sys.argv) == 3):
        k = float(sys.argv[2])
        calcul_wgrowth_rate(n, k)
    else:
        i0 = int(sys.argv[2])
        i1 = int(sys.argv[3])
        calcul_wgeneration(n, i0, i1)