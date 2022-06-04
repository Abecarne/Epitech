/*
** EPITECH PROJECT, 2020
** projets
** File description:
** help
*/

#include "include/defender.h"

void print_interactions(void)
{
    my_printf("  ESCAPE                pause menu\n");
}

void help(void)
{
    my_printf("Tower Defense created with CSFML.\n\n");
    my_printf("Defend your house from the terrifying (or not) zombies !\n");
    my_printf("USAGE\n ./my_defender \n\n");
    my_printf("USER INTERACTIONS\n");
    print_interactions();
}