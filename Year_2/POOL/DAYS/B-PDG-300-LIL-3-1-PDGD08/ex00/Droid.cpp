/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) :
    _energy(50),
    _attack(25),
    _toughness(15),
    _id(id)
{
    _status = new std::string("Standing by");
    std::cout << "Droid '" << id << "' Activated\n";
}

Droid::Droid(const Droid &droid) :
    _id(droid._id),
    _energy(droid._energy),
    _attack(droid._attack),
    _toughness(droid._toughness)
{
    _status = new std::string(*droid._status);
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped\n";
}

Droid::~Droid()
{
    delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &droid)
{
	_id = droid.getId();
	_energy = droid.getEnergy();
    delete(_status);
    _status = new std::string(*droid._status);
	return (*this);
}

bool Droid::operator==(const Droid &droid) const
{
    return (_id == droid._id &&
            _energy == droid._energy &&
            _attack == droid._attack &&
            _toughness == droid._toughness &&
            *getStatus() == *(droid.getStatus()));
}

bool Droid::operator!=(const Droid &droid) const
{
    return (!(droid == *this));
}

Droid &Droid::operator<<(size_t &reload)
{
    size_t added;

    if (_energy >= 100)
        return (*this);
    added = (100 - _energy);
    _energy += added;
    reload -= added;
    return (*this);
}
        
std::string Droid::getId(void) const
{
    return (_id);
}
        
void Droid::setId(std::string id)
{
    _id = id;
}
        
size_t Droid::getEnergy(void) const
{
    return (_energy);
}
        
void Droid::setEnergy(size_t energy)
{
    _energy = energy;
    if (100 < energy)
        _energy = 100;
}
        
size_t Droid::getAttack(void) const
{
    return (_attack);
}
        
size_t Droid::getToughness(void) const
{
   return (_toughness);
}
        
std::string *Droid::getStatus(void) const
{
    return (_status);
}
        
void Droid::setStatus(std::string *status)
{
    _status = status;
}

std::ostream &operator<<(std::ostream &target, const Droid &droid)
{
    return (target << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy());
}