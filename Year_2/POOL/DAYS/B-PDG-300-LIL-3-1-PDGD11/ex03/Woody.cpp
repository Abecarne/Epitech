/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string ascii) :
    Toy(WOODY, name, ascii)
{
}

Woody::~Woody()
{
}

void Woody::speak(const std::string &statement) const
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
}