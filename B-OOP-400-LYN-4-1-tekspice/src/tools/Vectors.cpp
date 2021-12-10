/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Vectors.cpp
*/

#include "Vectors.hpp"

Vectors::Vectors()
{
    return;
}

Vectors::~Vectors()
{
    return;
}

int Vectors::get_key(std::vector<std::string> array, std::string value)
{
    int index = 0;

    for (auto i = array.begin(); i != array.end(); ++i, index++) {
        if (*i == value)
            return (index);
    }

    return (-1);
}

int Vectors::count(std::vector<std::string> array)
{
    int index = 0;

    for (auto i = array.begin(); i != array.end(); ++i, index++);

    return (index);
}

std::string Vectors::get_value_from_key(std::vector<std::string> array, int index)
{
    int current = 0;

    for (auto i = array.begin(); i != array.end(); ++i, current++) {
        if (current == index)
            return (*i);
    }

    return ("_EMPTY_");
}

std::string Vectors::click(std::vector<std::string> array_keys, std::vector<std::string> array_values, std::string pin)
{
    int index = Vectors::get_key(array_keys, pin);

    return (Vectors::get_value_from_key(array_values, index));
}