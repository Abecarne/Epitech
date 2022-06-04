/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Borg
*/

#include "Borg.hpp"
#include <iostream>

// ~~~~~~~~~~~~~~~~~~~ Borg::Ship class ~~~~~~~~~~~~~~~~~~~
Borg::Ship::Ship(int weaponFrequency, short repair)
{
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = weaponFrequency;
    _repair = repair;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();

    if (stable)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;

}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = _home;
            return (true);
        }
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = d;
            return (true);
        }
    }
    return (false);
}

bool Borg::Ship::move(void)
{
    if (_core->checkReactor()->isStable() && _location != _home) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield(void)
{
    return (_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency(void)
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair(void)
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - _weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair(void)
{
    if (_repair > 0) {
        _repair--;
        _shield = 100;
        std::cout << "Begin shield re-initialisation ... Done. Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted , shield weakening." << std::endl;
    }
}
// ~~~~~~~~~~~~~~~~ End of Borg::Ship class ~~~~~~~~~~~~~~~~
