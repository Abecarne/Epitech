/*
** EPITECH PROJECT, 2021
** free_engine.c
** File description:
** free engine
*/

#include "my.h"
#include "framing_engine.h"

char *my_free(char *str)
{
    if (str != NULL)
        free(str);
    return (NULL);
}

char **free_str(char **str)
{
    if (str != NULL) {
        for (int i = 0; str[i] != NULL; i++)
            free(str[i]);
        free(str);
    }
    return (NULL);
}

void free_rpg(framing *lvl, input_manager *input)
{
    unload_input(input);
    unload_framing(lvl);
}
