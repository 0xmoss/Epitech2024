/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** logs.cpp
*/

#include "tools.hpp"

void logs::display(std::string message)
{
    std::cout << message << std::endl;
}

void logs::error(std::string message)
{
    std::cerr << message << std::endl;
}

void logs::help(std::string bin)
{
    std::cout << "Usage: " << bin << " <graphical> <game>" << std::endl;
    logs::display("Required: graphical");
}

