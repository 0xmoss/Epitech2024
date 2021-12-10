/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4071.cpp
*/

#include "4071.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4071_::_4071_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4071_::~_4071_()
{
    return;
}

void _4071_::simulate(std::size_t tick)
{
    Table table;
    Vectors vectors;
    std::string pin;

    for (size_t i = 0; i < vectors.count(this->factory->output_values_l); i++) {
        pin = this->factory->output_pins_l[i];
        if (pin == "3") {
            this->factory->output_values_l.at(i) = factory->simulate_or("1", "2");
        }
        if (pin == "4") {
            this->factory->output_values_l.at(i) = factory->simulate_or("5", "6");
        }
        if (pin == "11") {
            this->factory->output_values_l.at(i) = factory->simulate_or("12", "13");
        }
        if (pin == "10") {
            this->factory->output_values_l.at(i) = factory->simulate_or("8", "9");
        }
    }

    return;
}

nts::Tristate _4071_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4071_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4071_::dump() const
{
    return;
}