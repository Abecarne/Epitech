##
## EPITECH PROJECT, 2022
## PROJECTS [WSL: Ubuntu-20.04]
## File description:
## calculs
##

import math
import data

def arithmeticMean(userInput, datas : data.Data):
    """
    """
    if (datas.nbValues == 1):
        return userInput
    return (datas.arithmeticMean * datas.nbValues + userInput) / (datas.nbValues + 1)

def harmonicMean(userInput, datas : data.Data):
    """
    """
    if (datas.nbValues == 1):
        return userInput
    if (datas.harmonicMean != 0 and userInput != 0):
        return 1 / ((1 / datas.harmonicMean) + ((1 / userInput) - (1 / datas.harmonicMean)) / datas.nbValues)

def standardDeviationRoot(userInput, datas : data.Data):
    """
    """
    if (datas.nbValues == 1):
        return 0
    res = math.sqrt((pow(datas.standardDeviation, 2) + pow(datas.arithmeticMean, 2)) * (datas.nbValues - 1))
    return res

def standardDeviation(userInput, datas : data.Data):
    """
    """
    if (datas.nbValues == 1):
        return 0
    res = ((datas.nbValues - 2) * datas.standardDeviation ** 2) + (userInput - datas.arithmeticMean) * (userInput - datas.arithmeticMean)
    return math.sqrt(res / (datas.nbValues - 1))

def rootMean(userInput, datas : data.Data):
    """
    """
    if (datas.nbValues == 1):
        return userInput
    datas.rootMean = math.sqrt((pow(datas.standardDeviationRoot, 2) + pow(userInput, 2)) / datas.nbValues)
    return datas.rootMean

def calcul(userInput, datas : data.Data):
    """
    """
    datas.harmonicMean = harmonicMean(userInput, datas)
    datas.standardDeviationRoot = standardDeviationRoot(userInput, datas)
    datas.standardDeviation = standardDeviation(userInput, datas)
    datas.arithmeticMean = arithmeticMean(userInput, datas)
    datas.rootMean = rootMean(userInput, datas)
