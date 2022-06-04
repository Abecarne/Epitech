##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## printing
##

def printing(esp, standarDeviation, five, nine, one, two):
    """
    """
    print("Average return time: {:.0f}m {:.0f}s".format((esp * 60) // 60, (esp * 60) % 60))
    print("Standard deviation: {:.3f}".format(standarDeviation))
    print("Time after which 50% of the ducks are back: {:.0f}m ".format((five * 60) // 60) + "%02ds" % ((five * 60) % 60))
    print("Time after which 99% of the ducks are back: {:.0f}m ".format((nine * 60) // 60) + "%02ds" % ((nine * 60) % 60))
    print("Percentage of ducks back after 1 minute: {:.1f}%".format(one))
    print("Percentage of ducks back after 2 minutes: {:.1f}%".format(two))
