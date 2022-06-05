##
## EPITECH PROJECT, 2021
## sem2 [WSL: Ubuntu-20.04]
## File description:
## 108trigo
##

import sys
from math import *
from functions import *

def display_matrice(matrice):
    taille = len(matrice)
    if taille == 1:
        print("%.2f" % matrice[0])
        return 0
    for i in range(len(matrice)):
        if taille < 3:
            print("%.2f" % matrice[i][0], "\t", "%.2f" % matrice[i][1])
        else:
            print("%.2f" % matrice[i][0], "\t", "%.2f" % matrice[i][1], "\t", "%.2f" % matrice[i][2])

def make_matrice(argv):
    if (len(sys.argv) - 2) == 4:
        matrice = [[0, 0], [0, 0]]
    elif (len(sys.argv) - 2) == 9:
        matrice = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    else:
        matrice = [0]
    return matrice


def fill_matrice(argv, matrice, taille):
    k = 2
    if taille == 1:
        matrice[0] = float(argv[2])
        return matrice
    for i in matrice:
        for j in range(taille):
            i[j] = float(argv[k])
            k += 1
    return matrice

def dispatch_fct(argv):
    if (len(sys.argv) - 2) == 4:
        taille = 2
    elif (len(sys.argv) - 2) == 9:
        taille = 3
    else:
        taille = 1
    matrice = make_matrice(argv)
    matrice = fill_matrice(argv, matrice, taille)
    if argv[1] == "COS":
        res = fct_cos(matrice)
    if argv[1] == "COSH":
        res = fct_cosh(matrice)
    if argv[1] == "SIN":
        res = fct_sin(matrice)
    if argv[1] == "SINH":
        res = fct_sinh(matrice)
    if argv[1] == "EXP":
        res = fct_exp(matrice)
    display_matrice(res)

def get(mat, x, y):
    return mat[y][x]

def set(mat, x, y, val):
    mat[y][x] = val

def copieMatCarree(mat):
    n = len(mat)
    return list(list(mat[y][x] for x in range(0, n)) for y in range(0, n))

def newMatCarreeVide(n):
    return list(list(0 for x in range(0, n)) for y in range(0, n))

def printMatCarree(mat):
    n = len(mat)
    for y in range(0, n):
        for x in range(0, n):
            print(str(get(mat, x, y)) + '\t', end='')
        print()

def matrice_unitaire(n):
    return list(list(1 for x in range(0, n)) for y in range(0, n))

def matCareePower(A, n):
    An = copieMatCarree(A)
    length = len(A)
    for u in range(0, n-1):
        newAn = newMatCarreeVide(length)
        for x in range(0, length):
            for y in range(0, length):
                scal_ici = 0
                for i in range(0, length):
                    scal_ici += get(An, i, y) * get(A, x, i)
                set(newAn, x, y, scal_ici)
        An = newAn
    return An


def addition_matrice(mat1, mat2):
    """
    """
    res = newMatCarreeVide(len(mat1))
    for i in range(len(mat1)):
        for j in range(len(mat1)):
            res[i][j] = mat1[i][j] + mat2[i][j]
    return res
        
    