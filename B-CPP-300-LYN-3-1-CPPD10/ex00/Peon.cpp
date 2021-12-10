/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Peon.cpp
*/

#include <iostream>

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    const char *zog = "Zog zog.";

    std::cout << zog << std::endl;
}

Peon::~Peon()
{
    const char *bleuark = "Bleuark...";

    std::cout << bleuark << std::endl;
}

void Peon::getPolymorphed() const
{
    const char *pony = " has been turned into a pink pony!";

    std::cout << this->name << pony << std::endl;
}