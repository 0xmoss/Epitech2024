/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"


WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
    return;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return(this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool val)
{
    this->_stability = val;
}

WarpSystem::Core::Core(QuantumReactor *reactor)
{
    this->_coreReactor = reactor;
}

WarpSystem::Core::~Core()
{
    return;
}

bool WarpSystem::Core::isStable()
{
    return(this->_coreReactor->isStable());
}

WarpSystem::QuantumReactor *WarpSystem::Core::getQuantumReactor()
{
    return(this->_coreReactor);
}

void WarpSystem::Core::setStability(bool stability)
{
    this->_coreReactor->setStability(stability);
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return(this->_coreReactor);
}