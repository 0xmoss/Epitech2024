/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

nts::Tristate transform::btotri(bool value)
{
    if (value == true)
        return (nts::TRUE);
    if (value == false)
        return (nts::FALSE);
    return (nts::UNDIFINED);
}

std::string transform::btos(bool value)
{
    if (value == true)
        return ("1");
    if (value == false)
        return ("0");
    return ("U");
}

bool transform::stob(std::string value)
{
    if (value == "1")
        return (true);
    if (value == "0")
        return (false);
    return (-true);
}