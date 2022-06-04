##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## print
##

def printJointLaw(tab, tab2):
    print("--------------------------------------------------------------------------------")
    val = 10
    ind = 0
    print("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law")
    for i in tab:
        print("Y=%d" % val, end='\t')
        for j in i:
            print("%.3f" % j, end='\t')
        print("%.3f" % tab2[1][ind], end='')
        print("")
        val += 10
        ind += 1
    ind = 0
    print("X law", end='\t')
    for i in range(len(tab2[0])):
        print("%.3f" % tab2[0][i], end='\t')
        ind += 1
    print("1.000")

def printZTab(tab):
    print("--------------------------------------------------------------------------------")
    print("z\t20\t30\t40\t50\t60\t70\t80\t90\t100\np(Z=z)\t", end='')
    for i in range(len(tab)):
        if i == len(tab) - 1:
            print("%.3f" % tab[i])    
        else:
            print("%.3f" % tab[i], end='\t')

def printExpectedAndVariance(espX, varX, espY, varY, espZ, varZ):
    print("--------------------------------------------------------------------------------")
    print("expected value of X:\t%.1f" % espX)
    print("variance of X:\t\t%.1f" % varX)
    print("expected value of Y:\t%.1f" % espY)
    print("variance of Y:\t\t%.1f" % varY)
    print("expected value of Z:\t%.1f" % espZ)
    print("variance of Z:\t\t%.1f" % varZ)
    print("--------------------------------------------------------------------------------")