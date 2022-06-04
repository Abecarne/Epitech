/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii) :
    Toy(BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string &statement) const 
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}