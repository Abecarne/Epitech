/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** recup_lidar
*/

#include "my.h"
#include "ai.h"

bool my_str_isnum_point(char const *str)
{
    if (str[0] == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' && str[i] > '9' && str[i] != '.')
            return false;
    return true;
}

float *copy_in_value(char *str_lidar, float *value)
{
    char *tmp = malloc(sizeof(char) * 64);

    for (int i = 0; i != 3; i++) {
        if (i == 0)
            tmp = strtok(str_lidar, ":");
        else
            tmp = strtok(NULL, ":");
    }
    for (int i = 0; i != 32; i++) {
        if (i == 31)
            tmp = strtok(NULL, "\0");
        else
            tmp = strtok(NULL, ":");
        value[i] = atof(tmp);
    }
    return value;
}

float *create_lidar(sett *set)
{
    int cpt = 0;
    size_t a;
    char *str_lidar = malloc(sizeof(char) * 512);
    int b = 0;
    char c;
    write(1, "GET_INFO_LIDAR\n", 15);
    getline(&str_lidar, &a, stdin);
    set->value_radar = copy_in_value(str_lidar, set->value_radar);
    free(str_lidar);
    return set->value_radar;
}