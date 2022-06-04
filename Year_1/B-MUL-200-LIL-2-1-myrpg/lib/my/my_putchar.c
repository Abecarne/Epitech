/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** put charater
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
