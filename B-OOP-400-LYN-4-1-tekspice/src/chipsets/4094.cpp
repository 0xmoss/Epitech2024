/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4094.cpp
*/

#include "4094.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4094_::_4094_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4094_::~_4094_()
{
    return;
}

void _4094_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4094_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4094_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4094_::dump() const
{
    return;
}