/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "../include/Header.hpp"

int main(int ac, char **av)
{
    std::vector<std::unique_ptr<nts::IComponent>> allChipsets;
    size_t tick = 0;

    try {
        Error(ac, av);
        Parser parser(av[1]);
        allChipsets = createComponent(parser);
        setAllLinks(allChipsets, parser);
        shell(parser, allChipsets, &tick);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}