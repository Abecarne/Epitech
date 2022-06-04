/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** main
*/
#include <unistd.h>

char *final_string(int ac, char **av);

int main(int ac, char **av)
{
    if (ac != 3) {
        write(2, "\033[31mWrong argument\033[0m\n", 24);
    } else {
        final_string(ac, av);
    }

    return (0);
}
