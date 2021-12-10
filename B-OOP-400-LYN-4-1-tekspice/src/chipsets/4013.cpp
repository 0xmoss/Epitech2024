/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4013.cpp
*/

#include "4013.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4013_::_4013_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4013_::~_4013_()
{
    return;
}

void _4013_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4013_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4013_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4013_::dump() const
{
    return;
}