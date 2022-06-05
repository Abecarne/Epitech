##
## EPITECH PROJECT, 2022
## PROJECTS
## File description:
## calculs
##

from cmath import nan
import printValues, error
import statistics

def getPeriodAverage(tab, period):
    sum = 0
    if (len(tab) < period):
        return nan
    else:
        for i in range(len(tab) - period, len(tab)):
            sum += tab[i][1]
        return sum / period

def getTupleFromList(tab):
    tup1 = ([])
    tup2 = ([])
    for i in tab:
        tup1 += [i[0], ]
        tup2 += [i[1], ]
    return (tup1, tup2)

def getGValue(tab, period):
    """
    """
    sum = 0
    if (len(tab) < period + 1):
        return nan
    else:
        for i in range(len(tab) - period, len(tab)):
            if (tab[i - 1][1] <= tab[i][1]):
                sum += tab[i][1] - tab[i - 1][1]
        return sum / period

def getRValue(tab, period):
    """
    """
    sum = 0
    if (len(tab) < period + 1):
        return nan
    else:
        if (tab[len(tab) - period - 1][1] == 0):
            return 0
        sum = (tab[len(tab) - 1][1] - tab[len(tab) - period - 1][1]) / tab[len(tab) - period - 1][1] * 100
        return sum

def getSValue(tab, period):
    """
    """
    t = []
    sum = 0
    if (len(tab) < period):
        return nan
    else:
        for i in range(len(tab) - period, len(tab)):
            t.append(tab[i][1])

    sum = statistics.pstdev(t)
    return sum

def mainCalcul(period):
    """
    """
    tab = []
    cpt = 0
    state = 1
    switch = 0

    while(True):
        try:
            user_input = input()
        except EOFError:
            error.errorEOF()
        if (user_input == "STOP"):
            break
        else:
            error.errorInput(user_input)
        tab.append([cpt, float(user_input)])
        g = getGValue(tab, period)
        r = getRValue(tab, period)
        s = getSValue(tab, period)
        print("g=%.2f" % g + "\t\tr=%.0f" % r + "%%\t\ts=%.2f" % s, end='')
        if ((state > 0 and r > 0) or (state < 0 and r < 0)) or (len(tab) <= period):
            print('')
        elif ((state > 0 and r < 0) or (state < 0 and r > 0)):
            state *= -1
            switch += 1
            print("\t\ta switch occurs")
        else:
            print('')
        cpt += 1
    if (cpt < period):
        error.errorNotEnoughValues(period)
    printValues.printTendancy(switch)