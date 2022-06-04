/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** main
*/

#include "../include/main.hpp"

int main(int ac, char **av)
{
    try {
        arcade::core::Core core(ac, av);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
