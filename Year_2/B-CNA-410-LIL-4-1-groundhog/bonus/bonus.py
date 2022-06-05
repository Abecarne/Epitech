##
## EPITECH PROJECT, 2022
## PROJECTS
## File description:
## bonus
##

import matplotlib.pyplot as plt

def displayPlot(tupl, average):
    plt.plot(tupl[0], average)
    plt.plot(tupl[0], tupl[1])
    plt.title("Groundhog Visualization")
    plt.grid(True)
    plt.show()