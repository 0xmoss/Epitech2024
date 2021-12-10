/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4030.cpp
*/

#include "4030.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4030_::_4030_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4030_::~_4030_()
{
    Table table;
    Vectors vectors;
    std::string pin;

    for (size_t i = 0; i < vectors.count(this->factory->output_values_l); i++) {
        pin = this->factory->output_pins_l[i];
        if (pin == "3") {
            this->factory->output_values_l.at(i) = factory->simulate_xor("1", "2");
        }
        if (pin == "4") {
            this->factory->output_values_l.at(i) = factory->simulate_xor("5", "6");
        }
        if (pin == "11") {
            this->factory->output_values_l.at(i) = factory->simulate_xor("12", "13");
        }
        if (pin == "10") {
            this->factory->output_values_l.at(i) = factory->simulate_xor("8", "9");
        }
    }

    return;
}

void _4030_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4030_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4030_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4030_::dump() const
{
    return;
}