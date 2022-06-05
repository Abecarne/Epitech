##
## EPITECH PROJECT, 2022
## PROJECTS
## File description:
## error
##

import sys

def errorEOF():
    sys.stderr.write("Error: You must enter the keyword 'STOP'\n")
    sys.exit(84)

def errorNotEnoughValues(period):
    sys.stderr.write("Error: You must enter more than {} values\n".format(period))
    sys.exit(84)

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

def errorInput(input):
    for i in input:
        if (i != "-" and i != "+" and (i < "0" or i > "9") and i != "."):
            sys.stderr.write("Error: Arguments have to be numbers\n")
            sys.exit(84)

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
            sys.stderr.write("Error: Arguments have to be numbers\n")
            sys.exit(84)
        if int(sys.argv[1]) <= 0:
            sys.stderr.write("Error: numbers must be strictly greater than 0\n")
            sys.exit(84)
