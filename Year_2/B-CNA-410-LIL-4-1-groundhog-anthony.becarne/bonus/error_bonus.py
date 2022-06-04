##
## EPITECH PROJECT, 2022
## PROJECTS
## File description:
## error
##

import sys

def is_floatarg(str):
    try:
        float(str)
        return True
    except ValueError:
        return False

def errorHandling(argv):
    """
    """
    if len(argv) > 2:
        sys.stderr.write("Error: Too many arguments\n")
        sys.exit(84)
    elif len(argv) < 2:
        sys.stderr.write("Error: Not enough argument\n")
        sys.exit(84)
    else:
        if not is_floatarg(sys.argv[1]):
            sys.stderr.write("Error: Arguments have to be number\n")
            sys.exit(84)
        if int(sys.argv[1]) <= 0:
            sys.stderr.write("Error: numbers must greater than 1\n")
            sys.exit(84)
