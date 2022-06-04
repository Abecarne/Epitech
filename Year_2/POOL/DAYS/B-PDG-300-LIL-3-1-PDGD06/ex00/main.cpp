/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]\n";
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        std::ifstream ifs(av[i]);
        if (ifs.good()) {
            std::string content((std::istreambuf_iterator<char>(ifs)),
                                (std::istreambuf_iterator<char>()));
            std::cout << content;
        } else
            std::cerr << "my_cat: " << av[i] << ": No such file or directory";
    }
    std::cout << std::endl;
}