/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2- [WSL: Ubuntu-20.04]
** File description:
** Box
*/

#include <iostream>

#include "../Toy/Toy.hpp"
#include "../Wrap/Wrap.hpp"

void Box::wrapMeThat(Toy *toy)
{
    if (_is_open && _toy == nullptr) {
        _toy = toy;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    } else
        std::cerr << "The gift can't be wrapped" << std::endl;
}

Toy *Box::openMe()
{
    if (_is_open == false) {
        _is_open = true;
        return (_toy);
    }
    std::cerr << "Box is already open" << std::endl;
    return (_toy);
}

void Box::closeMe()
{
    if (_is_open == true)
        _is_open = false;
    else
        std::cerr << "Box is already closed" << std::endl;
}

Box::Box()
{
    _is_open = false;
}

Box::~Box()
{
    return;
}
