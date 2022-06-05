/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

class Component : public nts::IComponent {
    public:
        Component();
        Component(std::string name, nts::Type type, nts::Tristate = nts::UNDEFINED);
        ~Component();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        void setStatus(nts::Tristate state);
        nts::Type getComponentType(void);
        std::string getName(void);
        nts::Tristate getStatus(void);

    protected:
        std::string _name;
        int _maxPins;
        nts::Type _type;
        nts::Tristate _status;
};

#endif /* !COMPONENT_HPP_ */
