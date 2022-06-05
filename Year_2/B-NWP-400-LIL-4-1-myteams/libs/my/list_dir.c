/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** list_dir
*/

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int count_args_in_tab(char **tokens)
{
    int i = 0;

    while (tokens[i] != NULL)
        i++;
    return (i);
}

char **get_files_dir(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *ent;
    char **files = NULL;
    int i = 0;

    if (dir == NULL)
        return (NULL);
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') {
            files = realloc(files, sizeof(char *) * (i + 2));
            files[i] = strdup(ent->d_name);
            files[i + 1] = NULL;
            i++;
        }
    }
    closedir(dir);
    return (files);
}
