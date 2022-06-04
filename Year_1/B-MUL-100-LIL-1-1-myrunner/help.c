/*
** EPITECH PROJECT, 2020
** projets
** File description:
** help
*/

#include "include/struct.h"
#include "include/my.h"

void print_interactions(void)
{
    my_printf(" SPACE_KEY             jump.\n");
    my_printf(" MOUSE_LEFT_CLICK      shoot a fireball.\n");
    my_printf(" MOUSE_RIGHT_CLICK     reload the fireball shot.    /!\\");
    my_printf(" You have to reload before the first shot and then after");
    my_printf(" each shot /!\\\n\n");
}

void help(void)
{
    my_printf("\nFinite runner created with CSFML.\n\n");
    my_printf("To win, you have to kill/avoid at least 50 mobs or stay alive");
    my_printf(" for 2 minutes !\n\n");
    my_printf("USAGE\n ./my_runner map.txt\n\n");
    my_printf("OPTIONS\n -i                launch the game in infinity");
    my_printf(" mode.\n -h                print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    print_interactions();
}