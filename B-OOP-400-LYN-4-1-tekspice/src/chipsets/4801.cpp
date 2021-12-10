/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4801.cpp
*/

#include "4801.hpp"
#include "Interface.hpp"
#include "Transform.hpp"
#include "Factory.hpp"

_4801_::_4801_(Factory *factory)
{
    this->factory = factory;
    return;
}

_4801_::~_4801_()
{
    return;
}

void _4801_::simulate(std::size_t tick)
{
    return;
}

nts::Tristate _4801_::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void _4801_::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}

void _4801_::dump() const
{
    return;
}