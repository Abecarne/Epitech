/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** errors
*/

#include "../include/Errors.hpp"

Error::Error() {}

Error::Error(int ac, char **av)
{
    try {
        error(ac, av);
    } catch(const std::exception& e) {
        throw std::invalid_argument(e.what());
    }
}

Error::~Error() {}

void Error::help(void)
{
    std::cout << "USAGE:" << "\n";
    std::cout << "  ./arcade [library_path]" << "\n";
    std::cout << "DESCRIPTION:" << "\n";
    std::cout << "  [library_path] = path to the first library to open (normally located in ./lib/ folder)";
    std::cout << "  key 'Z'         move up" << "\n";
    std::cout << "  key 'Q'         move left" << "\n";
    std::cout << "  key 'S'         move down" << "\n";
    std::cout << "  key 'D'         move right" << "\n";
    std::cout << "  key 'Space'     launch the game" << "\n";
    std::cout << "  key 'Esc'       quit" << "\n";
    std::cout << "  key 'A'         change for previous graphic lib" << "\n";
    std::cout << "  key 'E'         change for next graphic lib" << "\n";
    std::cout << "  key 'O'         change for previous game lib" << "\n";
    std::cout << "  key 'P'         change for next game lib" << "\n";
    std::cout << "  key 'W'         get the Win screen" << "\n";
    std::cout << "  key 'L'         get the Lose screen" << "\n";
    std::cout << "\nALSO SEE THE DOCUMENTATION_ARCADE FOR MORE INFORMATIONS" << "\n";
}

void Error::error(int ac, char **av)
{
    if (ac != 2) {
        help();
        throw std::invalid_argument("");
    }
    try {
        isValidLib(av[1]);
    } catch(const std::exception& e) {
        throw std::invalid_argument(e.what());
    }
}

void Error::isValidLib(std::string filepath)
{
}
