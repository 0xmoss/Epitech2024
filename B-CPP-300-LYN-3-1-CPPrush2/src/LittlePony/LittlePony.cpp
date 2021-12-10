/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** LittlePony
*/

#include <iostream>

#include "LittlePony.hpp"

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
    m_is_taken = true;
}

void LittlePony::isDropped()
{
    m_is_taken = false;
}

LittlePony::LittlePony(const std::string *name, bool is_taken) : Toy(name, is_taken)
{
    return;
}

LittlePony::~LittlePony()
{
    return; 
}