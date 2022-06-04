/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int a = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            a = 10 * a;
            a =  a + (*str - 48);
        } else
            return (a);
        str++;
    }
    return (a);
}