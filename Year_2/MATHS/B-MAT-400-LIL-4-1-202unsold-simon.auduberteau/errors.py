##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## errors
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
    if len(sys.argv) < 3:
        sys.stderr.write("Error: Not enough arguments\n")
        sys.exit(84)
    if len(sys.argv) > 3:
        sys.stderr.write("Error: Too many arguments\n")
        sys.exit(84)
    for argv in sys.argv[1:]:
        if not is_intarg(argv):
            sys.stderr.write("Error arguments, a and b must be integers\n")
            sys.exit(84)
        if int(argv) < 50:
            sys.stderr.write("Error arguments, a and b must be greater than 50\n")
            sys.exit(84)