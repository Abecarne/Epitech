/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor;
    class Core;
};

#include <iostream>
#include "Destination.hpp"

namespace WarpSystem {

    class QuantumReactor
    {
        private:
            bool _stability = true;
            Destination _location;
            Destination _home;

        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };

    class Core
    {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();
            QuantumReactor *checkReactor(void);
    };
    
}
#endif /* !WARPSYSTEM_HPP_ */
