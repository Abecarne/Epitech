/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#ifndef RAMCORE
#define RAMCORE

#define KIBITOGIBI 9.5367431640625e-7

#include "header.hpp"

class RamCore
{
    private:
        long double _totMem;
        long double _freeMem;
        long double _usedMem;

        long double _totSwap;
        long double _freeSwap;
        long double _usedSwap;
    public:
        RamCore(void);
        long double convertKibi(long double) const;

//----------------------------Getters------------------------------------------
        long double getTotMem(void) const;
        long double getFreeMem(void) const;
        long double getUsedMem(void) const;

        long double getTotSwap(void) const;
        long double getFreeSwap(void) const;
        long double getUsedSwap(void) const;

        void refresh(void);
};

#endif