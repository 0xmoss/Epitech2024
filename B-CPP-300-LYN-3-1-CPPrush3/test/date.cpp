/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** date.cpp
*/

#include "date.hpp"

date::date()
{
    this->now = time(0);
    this->_date_ = "_EMPTY_";

    return;
}

date::~date()
{
    return;
}

void date::set()
{   
    this->_date_ = ctime(&this->now);
}

std::string date::get()
{
    if (this->_date_ == "_EMPTY_") {
        set();
    }

    return (ctime(&this->now));
}

void date::display()
{
    std::cout << get();

    return;
}
