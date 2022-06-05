/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Component
*/

#include "../../include/Header.hpp"

Component::Component()
{
}

Component::Component(std::string name, nts::Type type, nts::Tristate status) :
    _status(status),
    _name(name),
    _type(type)
{
}

Component::~Component()
{

}

void Component::simulate(std::size_t tick)
{

}

nts::Tristate Component::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}

std::string getTypeToString(nts::Type type)
{
    std::string the_string;

    switch (type) {
        case nts::TRUE_TYPE:
            the_string = "TRUE";
            break;
        case nts::FALSE_TYPE:
            the_string = "FALSE";
            break;
        case nts::OUTPUT:
            the_string = "OUTPUT";
            break;
        case nts::INPUT:
            the_string = "INPUT";
            break;
        case nts::CLOCK:
            the_string = "CLOCK";
            break;
        case nts::C_2716:
            the_string = "2716";
            break;
        case nts::C_4001:
            the_string = "4001";
            break;
        case nts::C_4008:
            the_string = "4008";
            break;
        case nts::C_4011:
            the_string = "4011";
            break;
        case nts::C_4013:
            the_string = "4013";
            break;
        case nts::C_4017:
            the_string = "4017";
            break;
        case nts::C_4030:
            the_string = "4030";
            break;
        case nts::C_4040:
            the_string = "4040";
            break;
        case nts::C_4069:
            the_string = "4069";
            break;
        case nts::C_4071:
            the_string = "4071";
            break;
        case nts::C_4081:
            the_string = "4081";
            break;
        case nts::C_4094:
            the_string = "4094";
            break;
        case nts::C_4512:
            the_string = "4512";
            break;
        case nts::C_4514:
            the_string = "4514";
            break;
        case nts::C_4801:
            the_string = "4801";
            break;
        default:
            break;
    }
    return (the_string);
}

void Component::dump(void) const
{
    std::string stringType = getTypeToString(_type);

    std::cout << "I am a chipset " << stringType << " ! You can call me '" << _name << "'" << std::endl;
}

void Component::setStatus(nts::Tristate state)
{
    _status = state;
}

nts::Type Component::getComponentType(void)
{
    return (_type);
}

std::string Component::getName(void)
{
    return (_name);
}

nts::Tristate Component::getStatus(void)
{
    return (_status);
}