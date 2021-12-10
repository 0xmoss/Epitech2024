/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 2716.cpp
*/

#include "2716.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_2716_::_2716_(Factory *factory)
{
    this->factory = factory;
    return;
}

_2716_::~_2716_()
{
    return;
}

void _2716_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _2716_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _2716_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _2716_::dump() const
{
    return;
}