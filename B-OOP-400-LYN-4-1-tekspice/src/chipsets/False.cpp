/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** False.cpp
*/

#include "False.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

False::False(Factory *factory)
{
    this->factory = factory;
    return;
}

False::~False()
{
    return;
}

void False::simulate(std::size_t tick)
{
    Table table;
    Vectors vectors;
    std::string pin;

    for (size_t i = 0; i < vectors.count(this->factory->output_values_l); i++) {
        this->factory->output_values_l.at(i) = "0";
    }

    return;
}

nts::Tristate False::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void False::dump() const
{
    return;
}