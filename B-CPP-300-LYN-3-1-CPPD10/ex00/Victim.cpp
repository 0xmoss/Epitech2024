/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Victim.cpp
*/

#include <iostream>
#include <string>

#include "Victim.hpp"

Victim::Victim(std::string name)
{
    this->name = name;

    std::cout << "Some random victim called " << this->name <<
    " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->name <<
    " just died for no apparent reason!" << std::endl;

    return;
}

std::string Victim::getName() const
{
    return (this->name);
}

void Victim::getPolymorphed() const
{
    std::cout << this->name <<
    " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator << (std::ostream &os, Victim const &victim)
{
    return (os << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}