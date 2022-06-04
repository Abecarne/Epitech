/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** ia
*/

#include "my.h"
#include "ai.h"

void show_value(float *value)
{
    fprintf(stderr, "SHOW VALUES\n");
    for (int i = 0; i != 32; i++)
        fprintf(stderr, "%.1f\n", value[i]);
    usleep(1);
}

void check_blocked(sett *set)
{
    int ret = 0;

    for (int i = 0; i != 32; i++)
        if (set->value_radar[i] < 400)
            ++ret;
    if (ret == 32)
        write(1, "STOP_SIMULATION\n", 16);
}

void start_simu(sett *set)
{
    write(1, "START_SIMULATION\n", 17);
    get_stdin(set);
    write(1, "CAR_FORWARD:0.3\n", 16);
    get_stdin(set);
}

void ia(void)
{
    sett set;

    init_struct(&set);
    start_simu(&set);
    while (1) {
        create_lidar(&set);
        change_dir(&set);
        check_blocked(&set);
    }
    write(2, "STOP_SIMULATION\n", 16);
}