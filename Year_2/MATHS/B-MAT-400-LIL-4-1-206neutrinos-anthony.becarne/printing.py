##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## printing
##

import data

def printing(datas : data.Data):
    """
    """
    print("    Number of values:   %.2f" % datas.nbValues)
    print("    Standard deviation: %.2f" % datas.standardDeviation)
    print("    Arithmetic mean:    %.2f" % datas.arithmeticMean)
    print("    Root mean square:   %.2f" % datas.rootMean)
    print("    Harmonic mean:      %.2f\n" % datas.harmonicMean)
