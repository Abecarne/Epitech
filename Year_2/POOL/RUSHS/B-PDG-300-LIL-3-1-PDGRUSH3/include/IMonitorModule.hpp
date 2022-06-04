/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include "header.hpp"

class IMonitorModule {
    public:
        // DTOR
        virtual ~IMonitorModule() {};
        virtual void refresh() = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
