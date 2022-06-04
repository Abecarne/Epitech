/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#include "../include/header.hpp"

AllInfo::AllInfo(void)
{
    this->_cpu = new Cpu;
    this->_info = new Info;
    this->_network = new Network;
    this->_ram = new RamCore;
}

AllInfo::~AllInfo(void)
{
    delete(this->_cpu);
    delete(this->_info);
    delete(this->_network);
    delete(this->_ram);
}

//-------------------------------Getters---------------------------------------

    Cpu *AllInfo::getCpu(void) const
    {
        return (this->_cpu);
    }

    Info *AllInfo::getInfo(void) const
    {
        return (this->_info);
    }

    Network *AllInfo::getNetwork(void) const
    {
        return (this->_network);
    }

    RamCore *AllInfo::getRamCore(void) const
    {
        return (this->_ram);
    }

//------------------------------End of Getters---------------------------------

void AllInfo::refresh(void)
{
    this->_cpu->refresh();
    this->_network->refresh();
    this->_ram->refresh();
}