/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum Type {
        INPUT,
        OUTPUT,
        CLOCK,
        TRUE_TYPE,
        FALSE_TYPE,
        C_2716,
        C_4001,
        C_4008,
        C_4011,
        C_4013,
        C_4017,
        C_4030,
        C_4040,
        C_4069,
        C_4071,
        C_4081,
        C_4094,
        C_4512,
        C_4514,
        C_4801
    };

    class IComponent {
        public :
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;

            virtual void setStatus(nts::Tristate state) = 0;
            virtual nts::Type getComponentType(void) = 0;
            virtual std::string getName(void) = 0;
            virtual nts::Tristate getStatus(void) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
