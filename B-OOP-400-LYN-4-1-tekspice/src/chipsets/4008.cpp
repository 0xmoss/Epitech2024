/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4008.cpp
*/

#include "4008.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4008_::_4008_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4008_::~_4008_()
{
    return;
}

void _4008_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4008_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4008_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4008_::dump() const
{
    return;
}