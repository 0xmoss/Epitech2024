/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Toy
*/
#include "../Object/Object.hpp"
#include "Toy.hpp"

Toy::Toy(const std::string *name, bool is_taken) : Object(name)
{
}

Toy::~Toy()
{
    return;
}