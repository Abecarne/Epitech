#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## B-MAT-100-LIL-1-1-104intersection-simon.auduberteau
## File description:
## 104intersection
##

import sys
from math import *


def delta(a, b, c):
    delta = (b**2) - (4 * a * c)
    return delta

def nb_roots(delta, a, b, c):
    if delta == 0:
        print("1 intersection point:")
        S = -(b / (2 * a))
        xn = int(sys.argv[2]) + S * int(sys.argv[5])
        yn = int(sys.argv[3]) + S * int(sys.argv[6])
        zn = int(sys.argv[4]) + S * int(sys.argv[7])
        print("(%.3f" % xn, ", %.3f" % yn, ", %.3f" % zn, ")", sep="")
    elif delta < 0:
        print("No intersection point.")
        return 0
    else:
        print("2 intersection points:")
        S1 = ((-b - sqrt(delta)) / (2 * a))
        S2 = ((-b + sqrt(delta)) / (2 * a))
        xn = int(sys.argv[2]) + S1 * int(sys.argv[5])
        yn = int(sys.argv[3]) + S1 * int(sys.argv[6])
        zn = int(sys.argv[4]) + S1 * int(sys.argv[7])
        xi = int(sys.argv[2]) + S2 * int(sys.argv[5])
        yi = int(sys.argv[3]) + S2 * int(sys.argv[6])
        zi = int(sys.argv[4]) + S2 * int(sys.argv[7])
        if S1 > S2:
            print("(%.3f" % xi, ", %.3f" % yi, ", %.3f" % zi, ")", sep="")
            print("(%.3f" % xn, ", %.3f" % yn, ", %.3f" % zn, ")", sep="")
        else:
            print("(%.3f" % xn, ", %.3f" % yn, ", %.3f" % zn, ")", sep="")
            print("(%.3f" % xi, ", %.3f" % yi, ", %.3f" % zi, ")", sep="")

def calcul_sphere():
    print("Sphere of radius" + " %s" % sys.argv[8])
    a = pow(int(sys.argv[5]), 2) + pow(int(sys.argv[6]), 2) + pow(int(sys.argv[7]), 2)
    b = 2 * (int(sys.argv[2]) * int(sys.argv[5]) + int(sys.argv[3]) * int(sys.argv[6]) + int(sys.argv[4]) * int(sys.argv[7]))
    c = pow(int(sys.argv[2]), 2) + pow(int(sys.argv[3]), 2) + pow(int(sys.argv[4]), 2) - int(sys.argv[8])**2
    if a == 0:
        sys.exit(84)
    print("Line passing through the point (" + "%s" % sys.argv[2] + ", %s" % sys.argv[3] + ", %s)" % sys.argv[4] + " and parallel to the vector (%s" % sys.argv[5] + ", %s" % sys.argv[6] + ", %s)" % sys.argv[7])
    D = delta(a, b, c)
    nb_roots(D, a, b, c)

def calcul_cylindre():
    print("Cylinder of radius" + " %s" % sys.argv[8])
    a = int(sys.argv[5])**2 + int(sys.argv[6])**2 + int(sys.argv[7])**2
    b = 2 * (int(sys.argv[2]) * int(sys.argv[5]) + int(sys.argv[3]) * int(sys.argv[6]))
    c = int(sys.argv[2])**2 + int(sys.argv[3])**2 - int(sys.argv[8])**2
    print(a)
    print(b)
    print(c)
    if a == 0:
        if sys.argv[7] == 0:
            sys.exit(84)
        else:
            if c == 0:
                print("straight line going through the (",sys.argv[2],",",sys.argv[3],",",sys.argv[4],") point and of direction vector (",sys.argv[5],",",sys.argv[6],",",sys.argv[7],")", sep="")
                print("There is an infinite number of intersection points.")
            else:
                print("straight line going through the (",sys.argv[2],",",sys.argv[3],",",sys.argv[4],") point and of direction vector (",sys.argv[5],",",sys.argv[6],",",sys.argv[7],")", sep="")
                print("No intersection point.")
    else:
        print("Line passing through the point (" + "%s" % sys.argv[2] + ", %s" % sys.argv[3] + ", %s)" % sys.argv[4] + " and parallel to the vector (%s" % sys.argv[5] + ", %s" % sys.argv[6] + ", %s)" % sys.argv[7])
    D = delta(a, b, c)
    nb_roots(D, a, b, c)

def calcul_cone():
    print("Cone with a" + " %s " % sys.argv[8] + "degree angle")
    ang = tan(radians(int(sys.argv[8])))**2
    a = int(sys.argv[5])**2 + int(sys.argv[6])**2 - int(sys.argv[7])**2 * ang
    b = 2 * (int(sys.argv[2]) * int(sys.argv[5]) + int(sys.argv[3]) * int(sys.argv[6]) - ang * int(sys.argv[4]) * int(sys.argv[7]))
    c = int(sys.argv[2])**2 + int(sys.argv[3])**2 - int(sys.argv[4])**2 * ang
    if a == 0:
        if b == 0:
            if c == 0:
                print("straight line going through the (",sys.argv[2],",",sys.argv[3],",",sys.argv[4],") point and of direction vector (",sys.argv[5],",",sys.argv[6],",",sys.argv[7],")", sep="")
                print("There is an infinite number of intersection points.")
            else:
                print("straight line going through the (",sys.argv[2],",",sys.argv[3],",",sys.argv[4],") point and of direction vector (",sys.argv[5],",",sys.argv[6],",",sys.argv[7],")", sep="")
                print("No intersection point.")
        else:
            L = -c / b
            print("straight line going through the (",sys.argv[2],",",sys.argv[3],",",sys.argv[4],") point and of direction vector (",sys.argv[5],",",sys.argv[6],",",sys.argv[7],")", sep="")
            print("1 intersection point :")
            xn = sys.argv[2] + L * sys.argv[5]
            yn = sys.argv[3] + L * sys.argv[6]
            zn = sys.argv[4] + L * sys.argv[7]
            print("(%.3f" % xn, ", %.3f" % yn, ", %.3f" % zn, ")", sep="")
    else:
        print("Line passing through the point (" + "%s" % sys.argv[2] + ", %s" % sys.argv[3] + ", %s)" % sys.argv[4] + " and parallel to the vector (%s" % sys.argv[5] + ", %s" % sys.argv[6] + ", %s)" % sys.argv[7])
    D = delta(a, b, c)
    nb_roots(D, a, b, c)