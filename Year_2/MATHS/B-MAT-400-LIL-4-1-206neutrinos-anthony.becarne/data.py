##
## EPITECH PROJECT, 2022
## PROJECTS [WSL: Ubuntu-20.04]
## File description:
## Data
##

import sys

class Data:
    nbValues = 0
    arithmeticMean = 0
    harmonicMean = 0
    standardDeviation = 0
    rootMean = 0
    standardDeviationRoot = 0

    def __init__(self):
        self.nbValues = int(sys.argv[1])
        self.arithmeticMean = int(sys.argv[2])
        self.harmonicMean = int(sys.argv[3])
        self.standardDeviation = int(sys.argv[4])

