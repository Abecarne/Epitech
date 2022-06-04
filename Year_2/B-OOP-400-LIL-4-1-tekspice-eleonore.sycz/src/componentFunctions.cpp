/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** componentFunctions
*/

#include "../include/Header.hpp"

std::string getStatusToString(nts::Tristate status)
{
    if (status == nts::TRUE)
        return ("1");
    else if (status == nts::FALSE)
        return ("0");
    else
        return ("U");
    
}

void displayAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick)
{
    std::string status;

    std::cout << "tick: " << *tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto & item : allChipsets) {
        if (item->getComponentType() == nts::INPUT || item->getComponentType() == nts::CLOCK) {
            status = getStatusToString(item->getStatus());
            std::cout << "  " << item->getName() << ": " << status << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto & item : allChipsets) {
        if (item->getComponentType() == nts::OUTPUT) {
            status = getStatusToString(item->getStatus());
            std::cout << "  " << item->getName() << ": " << status << std::endl;
        }
    }
}

void simulateAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick)
{
    for (auto && item : allChipsets) {
        item->simulate(*tick);
    }
    (*tick)++;
}

void breakLoop(int signal)
{}

void loopAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick)
{
    signal(SIGINT, breakLoop);

    while(usleep(10000) == 0) {
        simulateAll(allChipsets, tick);
        displayAll(allChipsets, tick);
    }
}

void dumpAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets)
{
    for (auto && item : allChipsets) {
        item->dump();
    }
}