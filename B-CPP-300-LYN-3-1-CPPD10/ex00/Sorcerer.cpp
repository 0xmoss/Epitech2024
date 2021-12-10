/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Sorcerer.cpp
*/

#include <iostream>
#include <string>

#include "Sorcerer.hpp"
#include "Peon.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->name = name;
    this->title = title;

    std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name << ", " << this->title <<
    ", is dead. Consequences will never be the same!" << std::endl;

    return;
}

std::string Sorcerer::getName() const
{
    return (this->name);
}

std::string Sorcerer::getTitle() const
{
    return (this->title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon) const
{
    peon.getPolymorphed();
}

std::ostream &operator << (std::ostream &os, Sorcerer const &sorcerer)
{
    return (os << "I am " << sorcerer.getName() << ", " <<
    sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}