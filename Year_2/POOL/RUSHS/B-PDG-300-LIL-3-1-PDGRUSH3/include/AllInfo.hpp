/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#ifndef ALLINFO
#define ALLINFO

#include "header.hpp"

class AllInfo
{
    private:
        Cpu *_cpu;
        Info *_info;
        Network *_network;
        RamCore *_ram;
    public:
        AllInfo(void);
        ~AllInfo(void);
        void refresh(void);

//----------------------------Getters------------------------------------------
        Cpu *getCpu(void) const;
        Info *getInfo(void) const;
        Network *getNetwork(void) const;
        RamCore *getRamCore(void) const;
};

#endif