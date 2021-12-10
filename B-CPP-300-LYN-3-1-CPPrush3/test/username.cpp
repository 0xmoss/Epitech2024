/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** username.cpp
*/

#include "username.hpp"

username::username()
{
    this->_username_ = "_EMPTY_";

    return;
}

username::~username()
{
    return;
}

std::string username::get()
{
    if (this->_username_ == "_EMPTY_") {
        set();
    }

    return (this->_username_);
}

void username::set()
{
    this->_username_ = getlogin();
}

void username::display()
{
    std::cout << get() << std::endl;

    return;
}