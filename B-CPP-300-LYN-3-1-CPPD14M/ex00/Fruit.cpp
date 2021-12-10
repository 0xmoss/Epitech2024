/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14M-
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit()
{
    this->name = "fruit";
    this->_vitamins = 0;
    return;
}

Fruit::Fruit(std::string const &_name_, int _vitamins_)
{
    this->name = _name_;
    this->_vitamins = _vitamins_;
    return;
}

Fruit::~Fruit()
{
    return;
}

std::string const &Fruit::getName()
{
    return(this->name);
}

int Fruit::getVitamins()
{
    return(this->_vitamins);
}