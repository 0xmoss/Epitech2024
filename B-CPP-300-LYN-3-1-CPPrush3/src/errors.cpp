/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** errors.cpp
*/

#include "errors.hpp"

errors::errors()
{
    return;
}

errors::~errors()
{
    return;
}

int errors::display(int type, std::string message)
{
    std::cout << "Error[" << type << "]: " << message << std::endl;

    return (type);
}