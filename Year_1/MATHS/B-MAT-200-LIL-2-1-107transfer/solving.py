##
## EPITECH PROJECT, 2021
## sem2 [WSL: Ubuntu-20.04]
## File description:
## 107transfer
##

import sys
from math import *

def calcul_fct(x, ac, str):
    result = 0.00000
    number = 0
    calc_x = 0
    tmp = 0
    nbr = sys.argv[ac].split("*")
    e = len(nbr) - 1

    # print(str)
    while e != -1:
        number = int(nbr[e])
        # print("number = %d" % number)
        calc_x = x**e
        # print("calcul de x", "(%.3f" % x, "** %d)" % e, "= %.5f" % calc_x) 
        tmp = number * calc_x
        # print("tmp (%d" % number, "* %.5f" % calc_x, "= %.5f" % tmp)
        result = result + tmp
        e = e - 1
        tmp = 0
    return result

def inter_calcul(x, ac, result):
    num = 0.00000
    dem = 0.00000

    num = calcul_fct(x, ac, "num")
    if ac + 1 != len(sys.argv):
        dem = calcul_fct(x, ac + 1, "dem")
    else:
        dem = 1
    # print("num = %.5f" % num)
    # print("dem = %.5f" % dem)
    result = result * (num / dem)
    # print("inter =", "%.5f" % result)
    return result

def calcul(tab):
    result = 1.00000
    x = 0.000
    num = 0
    den = 0
    ac = 1

    while x <= 1.001:
        while ac <= len(sys.argv) - 1:
            result = inter_calcul(x, ac, result)
            ac = ac + 2
        print("%.3f" % x, "->", "%.5f" % result)
        x += 0.001
        ac = 1
        result = 1.00000