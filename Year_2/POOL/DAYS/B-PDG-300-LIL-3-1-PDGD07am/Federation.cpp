/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Federation
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"

// ~~~~~~~~~~~~~~~~~~ Federation::Starfleet::Captain class ~~~~~~~~~~~~~~~~~~~~~~~~
Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName(void)
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge(void)
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}
// ~~~~~~~~~~~~~~~~~ End of Federation::Starfleet::Captain class ~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~ Federation::Starfleet::Ensign class ~~~~~~~~~~~~~~~~~~~~~~~~
Federation::Starfleet::Ensign::Ensign(std:: string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{ 
}
// ~~~~~~~~~~~~~~~~ End of Federation::Starfleet::Ensign class ~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~ Federation::Starfleet::Ship class ~~~~~~~~~~~~~~~
Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _location = _home;
    _shield = 100;
    _photonTorpedo = torpedo;

    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    _location = _home;
    _shield = 100;

    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship(void)
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();
    std::string str_stable = stable ? "stable" : "unstable";

    std::cout << "USS " << _name << ": The core is " << str_stable << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;

    std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp , Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = _home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = d;
            return (true);
        }
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{
    if (_core->checkReactor()->isStable() && _location != _home) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield(void)
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo(void)
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    } else {
        _photonTorpedo--;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo < torpedoes) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    } else if (_photonTorpedo == 0) {
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
        return;
    } else {
        _photonTorpedo--;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
        fire(_photonTorpedo, target);
    }
}
// ~~~~~~~~~~~~ End of Federation::Starfleet::Ship class ~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~ Federation::Ship class ~~~~~~~~~~~~~~~~~~~~~~~~
Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _location = _home;

    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship(void)
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();
    std::string str_stable = stable ? "stable" : "unstable";

    std::cout << _name << ": The core is " << str_stable << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = _home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        if (_location != _home) {
            _location = d;
            return (true);
        }
    }
    return (false);
}

bool Federation::Ship::move()
{
    if (_core->checkReactor()->isStable() && _location != _home) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return (_core);
}
// ~~~~~~~~~~~~~~~~~~ Federation::Ship class ~~~~~~~~~~~~~~~~~~~~~~~~