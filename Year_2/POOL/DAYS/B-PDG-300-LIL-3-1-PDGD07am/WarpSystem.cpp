/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

// ~~~~~~~~~~~~~~ WarpSystem::QuantumReactor class ~~~~~~~~~~~~~~~~~~~~~
WarpSystem::QuantumReactor::QuantumReactor()
{
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}
// ~~~~~~~~~~ End of WarpSystem::QuantumReactor class ~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~ WarpSystem::Core class ~~~~~~~~~~~~~~~~~~~
WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return (_coreReactor);
}
// ~~~~~~~~~~~~~~~~ End of WarpSystem::Core class ~~~~~~~~~~~~~~~~
