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
    if len(sys.argv) != 5:
        sys.stderr.write("Error: you must give strictly 4 argument\n")
        sys.exit(84)
    for i in sys.argv[1:]:
        if not is_intarg(i) or int(i) <= 0:
            sys.stderr.write("Error: arguments must be integers greater or equal than 0\n")
            sys.exit(84)

def errorInput(userInput):
    if userInput == "END":
        return
    if not is_intarg(userInput):
        sys.stderr.write("Error: you must enter a positive number\n")
        sys.exit(84)
