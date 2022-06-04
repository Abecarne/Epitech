/*
** EPITECH PROJECT, 2021
** build_map.c
** File description:
** build map
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>

int main(int ac, char **av)
{
    struct stat file;
    char *buff;
    int x = 0;
    int y = 0;
    int spawn = 0;
    int fd = 0;
    char *path;
    int hauteur = 0;
    int save = 0;
    int longueur = 0;

    if (ac != 2)
        return (84);
    path = av[1];
    fd = open(path, O_RDONLY);
    stat(path, &file);
    printf("taille de la map: %lli\n", file.st_size);

    buff = malloc(sizeof(char) * (file.st_size + 1));
    read(fd, buff, file.st_size);
    buff[file.st_size] = '\0';

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'G')
            printf("spawn point = %i %i\n", y, x);
        if (buff[i] == 'O') {
            spawn++;
            printf("spawn[%i] = [%i][%i]\n", spawn, y, x);
        }
        if (buff[i] == '\n') {
            x = 0;
            y++;
            hauteur++;
            if (longueur > save)
                save = longueur;
            longueur = 0;
        } else {
            x++;
            longueur++;
        }
    }
    printf("hauteur = %i\n", hauteur);
    printf("longueure = %i\n", save);
    free(buff);
    close (fd);
}
