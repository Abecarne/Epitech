##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## calculs
##

from webbrowser import get
import printCalculs

def calcul(a, b, x, y):
    return ((a - x) * (b - y)) / ((5*a - 150) * (5*b - 150))

def getTabJointLaw(a, b):
    joint = []
    for i in range(10, 60, 10):
        joint += [[float(calcul(a, b, j, i)) for j in range(10, 60, 10)]]
    return joint

def getTabMarginalLaw(tab):
    y = getTabMarginalLawY(tab)
    x = getTabMarginalLawX(tab)
    return (x, y)

def getTabMarginalLawY(tab):
    marginalY = []
    for i in tab:
        marginalY += [sum(i)]
    return marginalY

def getTabMarginalLawX(tab):
    marginalX = []
    for i in range(len(tab)):
        somme = 0
        for j in range(len(tab)):
            somme += tab[j][i]
        marginalX += [somme]
    return marginalX

def main_calcul(a, b):
    jointLaw = getTabJointLaw(a, b)
    margLaw = getTabMarginalLaw(jointLaw)
    printCalculs.printJointLaw(jointLaw, margLaw)
    tabZ = getZValue(jointLaw)
    printCalculs.printZTab(tabZ)
    espX = getExpectedValue(margLaw[0])
    espY = getExpectedValue(margLaw[1])
    espZ = getExpectedValueZ(tabZ)
    varX = getVariance(margLaw[0])
    varY = getVariance(margLaw[1])
    varZ = getVariance(tabZ)
    printCalculs.printExpectedAndVariance(espX, varX, espY, varY, espZ, varZ)

def getZValue(tab):
    z20 = tab[0][0]
    z30 = tab[0][1] + tab[1][0]
    z40 = tab[0][2] + tab[1][1] + tab[2][0]
    z50 = tab[0][3] + tab[1][2] + tab[2][1] + tab[3][0]
    z60 = tab[0][4] + tab[1][3] + tab[2][2] + tab[3][1] + tab[4][0]
    z70 = tab[1][4] + tab[2][3] + tab[3][2] + tab[4][1]
    z80 = tab[2][4] + tab[3][3] + tab[4][2]
    z90 = tab[3][4] + tab[4][3]
    z100= tab[4][4]
    return [z20, z30, z40, z50, z60, z70, z80, z90, z100]

def getExpectedValue(marginal):
    sum = 0
    val = 10
    for i in range(len(marginal)):
        sum += marginal[i] * val
        val += 10
    return sum

def getExpectedValueZ(marginal):
    sum = 0
    val = 20
    for i in range(len(marginal)):
        sum += marginal[i] * val
        val += 10
    return sum


def getVariance(tab):
    esp = getExpectedValue(tab)
    sum = 0
    val = 10
    for i in range(len(tab)):
        sum += tab[i] * (val*val)
        val += 10
    return sum - (esp * esp)