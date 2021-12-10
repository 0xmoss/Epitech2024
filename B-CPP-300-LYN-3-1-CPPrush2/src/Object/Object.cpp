/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Object
*/

#include <iostream>

#include "../Object/Object.hpp"

Object::Object(std::string const *name)
{
    _Name = name;
}

Object::~Object()
{
    return;
}