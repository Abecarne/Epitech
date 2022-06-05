#!/usr/bin/env python3
# ##
## EPITECH PROJECT, 2021
## delivery [WSL: fedora]
## File description:
## solving
##

import sys
from math import *

def define_f(val, x):
    """
    Renvoie valeur de f(x)
    """
    return ((val[0] * x**4) + (val[1] * x**3) + (val[2] * x**2) + (val[3] * x) + val[4])


def prime_f(val, x):
    """
    Renvoie la valeur de f'(x)
    """
    return (4 * val[0] * x**3 + 3 * val[1] * x**2 + 2 * val[2] * x + val[3])


def bisection(val):
    """
    Methode bisection
    """
    a = 0
    b = 1
    c = (a + b) / 2
    print("x =", c)
    while abs(define_f(val, c)) > 10**(-int(sys.argv[7])):
        if define_f(val, a)*define_f(val, c) > 0:
            a = c
        else:
            b = c
        c = (a + b) / 2
        if (float(("%." + sys.argv[7] + "f") % c) == c):
            print("x =", c)
        else:
            print(("x = %." + sys.argv[7] + "f") % c)
    return (val)


def newton(val):
    """
    Methode de Newton
    """
    a = 0.5
    fa = define_f(val, a)
    fpa = prime_f(val, a)
    pro = 0.5

    if (int(sys.argv[7]) == 0):
        print("x = 0")
    else:
        print("x = 0.5")
    while (abs(define_f(val, pro)) > 10**(-int(sys.argv[7]))):
        pro = a - (fa / fpa)
        a = pro
        fa = define_f(val, a)
        fpa = prime_f(val, a)
        if (float(("%." + sys.argv[7] + "f") % pro) == pro):
            print("x =", pro)
        else:
            print(("x = %." + sys.argv[7] + "f") % pro)
    return (val)



def secant(val):
    """
    Methode des secantes
    """
    x0 = 0
    x1 = 1
    xn = 0

    while abs(define_f(val, xn)) >= 10**(-int(sys.argv[7])):
        if define_f(val, x1) - define_f(val, x0) == 0:
            sys.stderr.write("Error, division by zero\n")
            sys.exit(84)
        xn = x1 - (define_f(val, x1) * (x1 - x0)) / (define_f(val, x1) - define_f(val, x0))
        x0 = x1
        x1 = xn
        if (float(("%." + sys.argv[7] + "f") % xn) == xn):
            print("x =", xn)
        else:
            print(("x = %." + sys.argv[7] + "f") % xn)
    return (val)

def solve(val):
    """
    """
    if sys.argv[1] == "1":
        if define_f(val, 0)*define_f(val, 1) < 0:
            bisection(val)
        else:
            sys.exit(84)
    elif sys.argv[1] == "2":
        newton(val)
    elif sys.argv[1] == "3":
        if 1 - (define_f(val, 1) * (1 - 0)) / (define_f(val, 1) - define_f(val, 0)) > 0:
            secant(val)
        else:
            sys.exit(84)
            
    else:
        sys.exit(84)
