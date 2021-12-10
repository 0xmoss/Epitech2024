/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Woody.cpp
*/

#include <iostream>

#include "Toy.hpp"
#include "Woody.hpp"

Woody::Woody(std::string const &name, std::string const &filename) :
    Toy(WOODY, name, filename)
{
    return;
}

Woody::Woody(const Woody & woody) : Toy(woody)
{
    return;
}

Woody::~Woody()
{
    return;
}

void Woody::display(const std::string message)
{
	std::cout << "WOODY: " << message << std::endl;
	return;
}
