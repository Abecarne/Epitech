/*
** EPITECH PROJECT, 2021
** abecarne
** File description:
** check_lap
*/

#include "ai.h"
#include "my.h"

char **separate_info(char *info_lap)
{
    for (int i = 0; info_lap[i] != '\0' ; i++) {
        info_lap[i] = (info_lap[i] == ' ') ? info_lap[i] = '_' : info_lap[i];
        info_lap[i] = (info_lap[i] == ':') ? info_lap[i] = ' ' : info_lap[i];
    }
    return (my_str_to_word_array(info_lap));
}

int work_tab(char **info)
{
    for (int i = 0; info[i] != NULL; i++) {
        if (strncmp(info[i], "First", 5) == 0 ||
            strncmp(info[i], "CP", 2) == 0 ||
            strncmp(info[i], "Lap", 3) == 0 ||
            strncmp(info[i], "Track_Cleared", 13) == 0)
        if (strncmp(info[i], "Track_Cleared", 13) == 0) {
            write(1, "CAR_FORWARD:0.0\n", 16);
            write(1, "STOP_SIMULATION\n", 16);
            exit(0);
        }
    }
}

int check_lap(sett *s)
{
    int cpt = 0;
    size_t a;
    char *info_lap = malloc(sizeof(char) * 512);
    char **info = NULL;

    write(1, "GET_INFO_SIMTIME\n", 17);
    getline(&info_lap, &a, stdin);
    info = separate_info(info_lap);
    work_tab(info);
    free(info_lap);
    return 0;
}