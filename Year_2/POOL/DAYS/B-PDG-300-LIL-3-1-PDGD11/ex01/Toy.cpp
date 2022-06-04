/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, const std::string &name, const std::string &filename) :
    _type(type),
    _name(name),
    _picture(filename)
{
}

Toy::Toy() :
    _type(BASIC_TOY),
    _name("toy"),
    _picture("")
{
}

Toy::Toy(const Toy &ref_toy) :
    _type(ref_toy.getType()),
    _name(ref_toy.getName()),
    _picture(ref_toy._picture)
{
}

Toy::~Toy()
{
}

Toy &Toy::operator=(const Toy &ref_toy)
{
    _type = ref_toy.getType();
    _name = ref_toy.getName();
    _picture = ref_toy.getAscii();
    return (*this);
}

int Toy::getType(void) const
{
    return (_type);
}

std::string Toy::getName(void) const
{
    return (_name);
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &filename)
{
    return (_picture.getPictureFromFile(filename));
}

std::string Toy::getAscii(void) const
{
    return (_picture.data);
}
