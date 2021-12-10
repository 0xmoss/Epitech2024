/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** true.cpp
*/

#include "True.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

True::True(Factory *factory)
{
    this->factory = factory;
    return;
}

True::~True()
{
    return;
}

void True::simulate(std::size_t tick)
{
    Table table;
    Vectors vectors;
    std::string pin;

    for (size_t i = 0; i < vectors.count(this->factory->output_values_l); i++) {
        this->factory->output_values_l.at(i) = "1";
    }

    return;
}

nts::Tristate True::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void True::dump() const
{
    return;
}