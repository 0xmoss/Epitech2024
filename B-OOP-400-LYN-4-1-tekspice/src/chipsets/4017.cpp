/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4017.cpp
*/

#include "4017.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4017_::_4017_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4017_::~_4017_()
{
    return;
}

void _4017_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4017_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4017_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4017_::dump() const
{
    return;
}