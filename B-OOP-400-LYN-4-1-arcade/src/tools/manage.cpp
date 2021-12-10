/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "tools.hpp"

char *manage::Set(std::string value)
{
    size_t size = value.length();
    char *result = static_cast<char*>(malloc(sizeof(char) * (size + 1)));

    for (size_t i = 0; i < size; i++) {
        result[i] = value[i];
    }
    result[size] = '\0';
    return (result);
}

