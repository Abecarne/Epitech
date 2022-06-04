/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ComponentFactory
*/

#include "../../include/Header.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}


std::unique_ptr<nts::IComponent> create2716(const std::string &value)
{
    return (std::unique_ptr<C_2716> {new C_2716(value)});
}

std::unique_ptr<nts::IComponent> create4001(const std::string &value)
{
    return (std::unique_ptr<C_4001> {new C_4001(value)});
}

std::unique_ptr<nts::IComponent> create4008(const std::string &value)
{
    return (std::unique_ptr<C_4008> {new C_4008(value)});
}

std::unique_ptr<nts::IComponent> create4011(const std::string &value)
{
    return (std::unique_ptr<C_4011> {new C_4011(value)});
}

std::unique_ptr<nts::IComponent> create4013(const std::string &value)
{
    return (std::unique_ptr<C_4013> {new C_4013(value)});
}

std::unique_ptr<nts::IComponent> create4017(const std::string &value)
{
    return (std::unique_ptr<C_4017> {new C_4017(value)});
}

std::unique_ptr<nts::IComponent> create4030(const std::string &value)
{
    return (std::unique_ptr<C_4030> {new C_4030(value)});
}

std::unique_ptr<nts::IComponent> create4040(const std::string &value)
{
    return (std::unique_ptr<C_4040> {new C_4040(value)});
}

std::unique_ptr<nts::IComponent> create4069(const std::string &value)
{
    return (std::unique_ptr<C_4069> {new C_4069(value)});
}

std::unique_ptr<nts::IComponent> create4071(const std::string &value)
{
    return (std::unique_ptr<C_4071> {new C_4071(value)});
}

std::unique_ptr<nts::IComponent> create4081(const std::string &value)
{
    return (std::unique_ptr<C_4081> {new C_4081(value)});
}

std::unique_ptr<nts::IComponent> create4094(const std::string &value)
{
    return (std::unique_ptr<C_4094> {new C_4094(value)});
}

std::unique_ptr<nts::IComponent> create4512(const std::string &value)
{
    return (std::unique_ptr<C_4512> {new C_4512(value)});
}

std::unique_ptr<nts::IComponent> create4514(const std::string &value)
{
    return (std::unique_ptr<C_4514> {new C_4514(value)});
}

std::unique_ptr<nts::IComponent> create4801(const std::string &value)
{
    return (std::unique_ptr<C_4801> {new C_4801(value)});
}

std::unique_ptr<nts::IComponent> createInput(const std::string &value)
{
    return (std::unique_ptr<C_input> {new C_input(value)});
}

std::unique_ptr<nts::IComponent> createOutput(const std::string &value)
{
    return (std::unique_ptr<C_output> {new C_output(value)});
}

std::unique_ptr<nts::IComponent> createTrue(const std::string &value)
{
    return (std::unique_ptr<C_true> {new C_true(value)});
}

std::unique_ptr<nts::IComponent> createFalse(const std::string &value)
{
    return (std::unique_ptr<C_false> {new C_false(value)});
}

std::unique_ptr<nts::IComponent> createClock(const std::string &value)
{
    return (std::unique_ptr<C_clock> {new C_clock(value)});
}

std::vector<std::unique_ptr<nts::IComponent>> createComponent(Parser parser)
{
    std::unique_ptr<nts::IComponent> (*arr[])(const std::string &value) = {
                                                &create2716,    &create4001,    &create4008,    &create4011,
                                                &create4013,    &create4017,    &create4030,    &create4040,
                                                &create4069,    &create4071,    &create4081,    &create4094,
                                                &create4512,    &create4514,    &create4801,    &createClock,
                                                &createFalse,   &createInput,   &createOutput,  &createTrue};

    std::vector<std::string> chipsetsType = {   "2716",         "4001",         "4008",         "4011",
                                                "4013",         "4017",         "4030",         "4040",
                                                "4069",         "4071",         "4081",         "4094",
                                                "4512",         "4514",         "4801",         "clock",
                                                "false",        "input",        "output",       "true"};
    
    std::vector<std::unique_ptr<nts::IComponent>> chipsets;

    for (auto item : parser.getTabInputs())
        for (int i = 0; i < chipsetsType.size(); i++)
            if (chipsetsType[i] == item.first)
                chipsets.push_back(arr[i](item.second));

    for (auto item : parser.getTabOutputs())
        for (int i = 0; i < chipsetsType.size(); i++)
            if (chipsetsType[i] == item.first)
                chipsets.push_back(arr[i](item.second));

    for (auto item : parser.getTabNames())
        for (int i = 0; i < chipsetsType.size(); i++)
            if (chipsetsType[i] == item.first)
                chipsets.push_back(arr[i](item.second));

    return (chipsets);
}