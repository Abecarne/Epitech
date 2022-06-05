/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** error
*/

#include "../include/main.h"

int help(int ac, char **av)
{
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE:\t ./myteams_cli ip port\n");
        printf("\tip\t");
        printf("is the server ip address on which");
        printf("the server socket listens\n");
        printf("\tport\t");
        printf("is the port number on which the server socket listens\n");
        return (0);
    } else {
        return (1);
    }
}

int check_int(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (atoi(av[2]) < 0)
        return (1);
    return (0);
}
