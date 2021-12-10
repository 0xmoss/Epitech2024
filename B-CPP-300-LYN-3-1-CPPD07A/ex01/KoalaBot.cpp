/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms& arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(Legs& legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(Head& head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms& arms)
{
    this->setParts(arms);
}

void KoalaBot::swapParts(Legs& legs)
{
    this->setParts(legs);
}

void KoalaBot::swapParts(Head& head)
{
    this->setParts(head);
}

void KoalaBot::informations()
{
    static const char *bot = "[KoalaBot] ";

    std::cout << bot << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status()
{
    return this->_arms.getFunctionnal()
        && this->_legs.getFunctionnal()
        && this->_head.getFunctionnal();
}