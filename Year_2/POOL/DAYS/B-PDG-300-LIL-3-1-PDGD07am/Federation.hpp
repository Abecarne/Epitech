/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ensign;
        class Ship;
    };
    class Ship;
};

#include <iostream>
#include "WarpSystem.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
            private:
                std::string _name;
                int _age = 0;

            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
        };

        class Ensign {
            private:
                std:: string _name;

            public:
                Ensign(std::string name);
                ~Ensign();
        };

        class Ship {
            private:
                int _length;
                int _width;
                int _shield;
                int _photonTorpedo;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location = EARTH;
                Destination _home;

            public:
                Ship();
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                void promote(Captain *captain);
                bool move(int warp , Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move(void);
                int getShield(void);
                void setShield(int shield);
                int getTorpedo(void);
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes , Borg::Ship *target);
        };
    };
    
    class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location = VULCAN;
            Destination _home;

        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore(void);
    };
};

#endif /* !FEDERATION_HPP_ */
