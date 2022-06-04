##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## error
##
import sys

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

def error():
    if len(sys.argv) != 2:
        sys.stderr.write("Error: you must give strictly 1 argument\n")
        sys.exit(84)
    if not is_floatarg(sys.argv[1]):
        sys.stderr.write("Error: 0 <= a <= 2.5\n")
        sys.exit(84)
    if not (0 <= float(sys.argv[1]) <= 2.5):
        sys.stderr.write("Error: 0 <= a <= 2.5\n")
        sys.exit(84)
