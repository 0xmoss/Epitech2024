/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4069.cpp
*/

#include "4069.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4069_::_4069_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4069_::~_4069_()
{
    return;
}

void _4069_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4069_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4069_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4069_::dump() const
{
    return;
}