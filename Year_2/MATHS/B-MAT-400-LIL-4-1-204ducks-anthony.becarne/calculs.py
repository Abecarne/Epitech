##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## calculs
##

from math import exp, pi, ceil, sqrt
import printing

def getDensity(a, t):
    res = a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t)
    return res

def areBack(a, cpt, nbr):
    """
    """
    i = 0.0
    density = 0.0
    while (i <= (cpt * nbr)):
        density += getDensity(a, i / 100)
        if (density >= cpt):
            return (i / 100)
        i += 1

def backAfter(a, cpt, nbr):
    """
    """
    i = 0
    density = 0.0
    while (i < cpt * 1000):
        density += getDensity(a, i / nbr)
        i += 1
    return density / 10

def fctDeviation(esp, a, t):
    return ((t - esp)**2) * (getDensity(a, t) / 10)

def calcEsperance(a, nbr):
    cpt = 0
    density = 0.0
    esp = 0.0
    while (cpt < nbr):
        density += (getDensity(a, cpt) / 10)
        esp += cpt * (getDensity(a, cpt) / 10)
        cpt += 0.001

    esp = esp / nbr
    return esp

def calcul(a):
    """
    """
    i = 0
    standarDeviation = 0.0
    five = 0.0
    nine = 0.0
    esp = calcEsperance(a, 99.999)

    while (i > 0):
        standarDeviation += fctDeviation(esp, a, i)
        i -= 0.001
    standarDeviation = standarDeviation / 99.9999
    standarDeviation = pow(standarDeviation, 0.5)

    five = areBack(a, 50, 100)
    nine = areBack(a, 99, 100)
    oneMinute = backAfter(a, 1, 1000)
    twoMinute = backAfter(a, 2, 1000)
    printing.printing(esp, standarDeviation, five, nine, oneMinute, twoMinute)
