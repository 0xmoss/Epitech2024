/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-
** File description:
** Borg.cpp
*/

#include "Borg.hpp"
#include "WarpSystem.hpp"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;

    std::cout << "We are the Borgs. Lower your shields and surrender" <<
    " yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies" <<
    " will be assimilated." << std::endl; 
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
    return;
}

bool Borg::Ship::isStable()
{
    if (this->getCore())
        return(this->getCore()->isStable());
    return(false);
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::setCore(WarpSystem::Core *core)
{
    this->_core = core;
}

WarpSystem::Core *Borg::Ship::Ship::getCore()
{
    return(this->_core);
}

void Borg::Ship::checkCore()
{
    if (this->_core) {
        if (this->_core->checkReactor()->isStable() == true)
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }
}
