/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD16-
** File description:
** DomesticKoala.cpp
*/

#include <iostream>
#include <string>

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(
    KoalaAction& action
) : action(action), knowAction(256)
{
    return;
}

DomesticKoala::~DomesticKoala()
{
    return;
}

DomesticKoala::DomesticKoala(
    DomesticKoala const &other
) : action(other.action), knowAction(other.knowAction)
{
    return;
}

DomesticKoala &DomesticKoala::operator = (DomesticKoala const &other)
{
    action = other.action;
    knowAction = other.knowAction;
    return (*this);
}

std::vector<DomesticKoala::methodPointer_t> const *DomesticKoala::getAction() const
{
    return (&knowAction);
}

void DomesticKoala::learnAction(char c, methodPointer_t ptr)
{
    knowAction[c] = ptr;
    return;
}

void DomesticKoala::unlearnAction(char c)
{
    knowAction[c] = NULL;
    return;
}

void DomesticKoala::doAction(char c, std::string const &str)
{
    methodPointer_t func = knowAction[c];

    if (func)
        (action.*func)(str);
    return;
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    action = action;
    return;
}