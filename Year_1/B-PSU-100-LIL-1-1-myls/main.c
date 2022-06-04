/*
** EPITECH PROJECT, 2020
** unix system
** File description:
** main
*/

#include <stdio.h>
#include <dirent.h>
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/macro.h"

int main(int ac, char **av)
{
    DIR *dir;
    struct dirent *dirinfo;
    struct stat sb;
    int i = 1;

    if (ac == 1) {
        dir = opendir("./");
        if (dir == NULL)
            return (84);
        while ((dirinfo = readdir(dir)) != NULL)
            if (dirinfo->d_name[0] == '.') {
                my_printf("");
            } else {
                my_printf("%s  ", dirinfo->d_name);
            }
    } else {
        while (ac != 1 && i < ac) {
        dir = opendir(av[i]);
        if (dir == NULL)
            return (84);
        while ((dirinfo = readdir(dir)) != NULL)
            if (dirinfo->d_name[0] == '.') {
                my_printf("");
            } else {
                my_printf("%s  ", dirinfo->d_name);
            }
        i++;
        }
    }
    my_printf("\n");
    return (0);
}