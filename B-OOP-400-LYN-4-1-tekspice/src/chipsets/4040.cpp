/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4040.cpp
*/

#include "4040.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4040_::_4040_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4040_::~_4040_()
{
    return;
}

void _4040_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4040_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4040_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4040_::dump() const
{
    return;
}