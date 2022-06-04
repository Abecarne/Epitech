/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg {
    class Ship;
};

#include "Federation.hpp"
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move(void);
            int getShield(void);
            void setShield(int shield);
            int getWeaponFrequency(void);
            void setWeaponFrequency(int frequency);
            short getRepair(void);
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair(void);

        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home = UNICOMPLEX;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */
