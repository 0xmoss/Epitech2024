/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4514.cpp
*/

#include "4514.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4514_::_4514_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4514_::~_4514_()
{
    return;
}

void _4514_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4514_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4514_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4514_::dump() const
{
    return;
}