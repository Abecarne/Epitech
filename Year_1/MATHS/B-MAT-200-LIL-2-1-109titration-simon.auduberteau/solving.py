##
## EPITECH PROJECT, 2021
## sem2 [WSL: Ubuntu-20.04]
## File description:
## 108trigo
##

import sys
from math import *

def is_intarg(str):
    try:
        int(str)
        return True
    except ValueError:
        return False

def is_floatarg(str):
    try:
        float(str)
        return True
    except ValueError:
        return False

def try_oprd(filename):
    try:
        with open(filename, 'r') as f:
            lines = f.read()
        f.close()
    except IOError:
        sys.stderr.write("Error: cannot open the file\n")
        sys.exit(84)
    return lines

def check_file(arr):
    cpt = 0

    for i in arr:
        j = 0
        while j != len(i):
            if i[j] == ';':
                cpt += 1
            j += 1
        if cpt == 0 or cpt > 1:
            sys.stderr.write("Error: wrong syntaxe in the file\n")
            sys.exit(84)
        cpt = 0
    for i in arr:
        tmp = i.split(';')
        if not is_intarg(tmp[0]) and not is_floatarg(tmp[0]):
            sys.stderr.write("Error: Put only number in the file\n")
            sys.exit(84)
        if not is_intarg(tmp[1]) and not is_floatarg(tmp[1]):
            sys.stderr.write("Error: Put only number in the file\n")
            sys.exit(84)

def error(tab_file):
    if len(tab_file) == 0:
        sys.stderr.write("Error: The file is empty\n")
        sys.exit(84)
    check_file(tab_file)

def titration(filename):
    file = try_oprd(filename)
    tab_file = file.split('\n')
    if tab_file[len(tab_file) - 1] == '':
        tab_file.pop()
    error(tab_file)
    tab_file = [i.split(';') for i in tab_file]
