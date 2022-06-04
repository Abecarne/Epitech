#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## PROJECTS [WSL: Ubuntu-20.04]
## File description:
## groundhog
##

import sys
import error, calculs

def main():
    """
    """
    error.errorHandling(sys.argv)
    calculs.mainCalcul(int(sys.argv[1]))

if __name__ == "__main__":
    main()
