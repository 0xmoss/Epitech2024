/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Buzz.cpp
*/

#include <iostream>

#include "Buzz.hpp"

Buzz::Buzz(std::string const &name, std::string const &filename) :
    Toy(BUZZ, name, "buzz.txt")
{
    return;
}

Buzz::Buzz(Buzz const &buzz) : Toy(buzz)
{
    return;
}

Buzz::~Buzz()
{
    return;
}

void Buzz::display(const std::string message)
{
	std::cout << "BUZZ: " << message << std::endl;
    
    return;
}