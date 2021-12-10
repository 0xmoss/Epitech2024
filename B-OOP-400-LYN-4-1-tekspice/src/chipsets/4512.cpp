/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4512.cpp
*/

#include "4512.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4512_::_4512_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4512_::~_4512_()
{
    return;
}

void _4512_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4512_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4512_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4512_::dump() const
{
    return;
}