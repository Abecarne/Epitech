/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** main
*/

#include "../include/header.hpp"
#include <string.h>
#include <iostream>

void help(void)
{
    std::cout << "USAGE\n" << std::endl;
    std::cout << "    Use -h for help." << std::endl;
    std::cout << "    Use --graph for launching the program in graphical mode." << std::endl;
    std::cout << "    Without any arguments launch into terminal mode.\n" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        init();
    } else if (ac == 2 && strcmp(av[1], "-h") == 0) {
        help();
    } else if (ac == 2 && strcmp(av[1], "--graph") == 0) {
        Display window;

        while (window.is_running()) {
            window.update();
            window.render();
        }
    }
    return (0);
}
