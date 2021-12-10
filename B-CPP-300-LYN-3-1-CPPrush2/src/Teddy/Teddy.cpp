/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Teddy
*/

#include <iostream>

#include "../Toy/Toy.hpp"
#include "Teddy.hpp"

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
    m_is_taken = true;
}

void Teddy::isDropped()
{
    m_is_taken = false;
}

Teddy::Teddy(const std::string *name, bool is_taken) : Toy(name, is_taken)
{
    return;
}

Teddy::~Teddy()
{
    return;   
}