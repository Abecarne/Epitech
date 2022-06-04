##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## printing
##


def print_all_infos(tab, a, b, cor, rms, pop):
    print_countries(tab)
    print_fit(a, b, rms, pop, 1)
    print_fit(a, b, rms, pop, 2)
    print_corr(cor)

def print_countries(tab):
    print("Country: ", end="")
    for i in range(len(tab)):
        if i == len(tab) - 1:
            print(tab[i][0])
        else:
            print(tab[i][0], end=", ")

def print_fit(a, b, rms, pop, number):
    print("Fit" + str(number))
    if number == 1:
        print(f"    Y = {a} X - {b}")
    else:
        print(f"    X = {a} Y - {b}")
    print(f"    Root-mean-square deviation: {rms}")
    print(f"    Population in 2050: {pop}")

def print_corr(cor):
    print(f"Correlation: {cor}")