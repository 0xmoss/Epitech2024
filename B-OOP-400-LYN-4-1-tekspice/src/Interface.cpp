/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Interface.cpp
*/

#include "Interface.hpp"

void nts::IComponent::simulate(std::size_t tick)
{
    return;
}

nts::Tristate nts::IComponent::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void nts::IComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin)
{
    return;
}