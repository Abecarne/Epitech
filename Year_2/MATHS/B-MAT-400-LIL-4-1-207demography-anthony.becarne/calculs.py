##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## calculs
##

from printing import *



# get the aX of the linear fit Y = aX - bX
def get_aX(tab):
    aX = 0
    for i in range(len(tab)):
        aX += float(tab[i][2]) * float(tab[i][3])
    aX /= len(tab)
    return aX

# get the bX of the linear fit Y = aX - bX
def get_bX(tab):
    bX = 0
    for i in range(len(tab)):
        bX += float(tab[i][2]) * float(tab[i][4])
    bX /= len(tab)
    return bX

# get the rms of the linear fit
def get_rms(tab, aX, bX):
    """
    """
    rms = 0
    for i in range(len(tab)):
        rms += (float(tab[i][2]) * (float(tab[i][3]) - aX) - float(tab[i][4]) + bX) ** 2
    rms /= len(tab)
    return rms

def get_corr(tab, aX, bX):
    cor = 0
    for i in range(len(tab)):
        cor += (float(tab[i][2]) * (float(tab[i][3]) - aX) - float(tab[i][4]) + bX) * (float(tab[i][3]) - aX)
    cor /= len(tab)
    return cor

def main_calcul(data):
    aX = get_aX(data)
    bX = get_bX(data)
    rms = get_rms(data, aX, bX)
    cor = get_corr(data, aX, bX)
    pop = aX * 2050 + bX
    print_all_infos(data, aX, bX, cor, rms, pop)