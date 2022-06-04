##
## EPITECH PROJECT, 2021
## B-MAT-200-LIL-2-1-108trigo-simon.auduberteau
## File description:
## functions
##

import sys
from math import *
from solving import *

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

def soustraction_matrice(mat1, mat2):
    """
    """
    res = newMatCarreeVide(len(mat1))
    for i in range(len(mat1)):
        for j in range(len(mat1)):
            res[i][j] = mat1[i][j] - mat2[i][j]
    return res


def div_matrice(mat, nb):
    """
    """
    res = newMatCarreeVide(len(mat))
    for i in range(len(mat)):
        for j in range(len(mat)):
            res[i][j] = mat[i][j] / nb
    return res


def fct_cos(matrice):
    """
    """
    n = 1
    res = matrice_unitaire(len(matrice))

    while (n < 80):
        if (n % 2 == 1):
            res = soustraction_matrice(res, div_matrice(matCareePower(matrice, 2 * n), factorial(2 * n)))
        elif (n % 2 == 0):
            res = addition_matrice(res, div_matrice(matCareePower(matrice, 2 * n), factorial(2 * n)))
        n += 1
    return (res)

def fct_sin(matrice):
    """
    """
    n = 1
    res = matrice
    while (n < 80):
        if (n % 2 == 1):
            res = soustraction_matrice(res, div_matrice(matCareePower(matrice, 2 * n + 1), factorial(2 * n + 1)))
        elif (n % 2 == 0):
            res = addition_matrice(res, div_matrice(matCareePower(matrice, 2 * n + 1), factorial(2 * n + 1)))
        n += 1
    return (res)

def fct_exp(matrice):
    """
    """
    n = 2
    res = addition_matrice(matrice_unitaire(len(matrice)), matrice)
    while (n < 80):
        res = addition_matrice(div_matrice(matCareePower(matrice, n), factorial(n)), res)
        n += 1
    return (res)

def fct_cosh(matrice):
    """
    """
    n = 1
    res = matrice
    while (n < 80):
        res = addition_matrice(res, div_matrice(matCareePower(matrice, 2 * n), factorial(2 * n)))
        n += 1
    return (res)

def fct_sinh(matrice):
    """
    """
    n = 1
    res = matrice
    while (n < 80):
        res = addition_matrice(res, div_matrice(matCareePower(matrice, 2 * n + 1), factorial(2 * n + 1)))
        n += 1
    return (res)