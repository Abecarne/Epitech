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
        printf("USAGE:\t./myftp port path\n");
        printf("\tport\t");
        printf("is the port number on which the server socket listens\n");
        printf("\tpath\t");
        printf("is the path to the home directory for the Anonymous user\n");
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

int check_path(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        printf("path isn't valid\n");
        return (1);
    }
    if (!S_ISDIR(sb.st_mode)) {
        printf("path isn't a directory\n");
        return (1);
    }
    return (0);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (atoi(av[1]) < 0)
        return (1);
    if (check_path(av[2]) == 1)
        return (1);
    return (0);
}
