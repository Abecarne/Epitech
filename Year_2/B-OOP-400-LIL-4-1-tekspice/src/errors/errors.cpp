#include "../../include/Header.hpp"

void errorFile(char *filename)
{
    std::ifstream ifs(filename);
    if (!ifs.good())
        throw std::invalid_argument("Unable to open the file.");
}

void Error(int ac, char **av)
{
    // ARGS
    if (ac != 2)
        throw std::invalid_argument("Not enough arguments.");

    // FILE
    try {
        errorFile(av[1]);
    } catch(const std::exception& e) {
        throw std::invalid_argument(e.what());
    }
}