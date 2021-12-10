/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Contains.cpp
*/

#include "Contains.hpp"

bool Contains_char(std::string str, char c)
{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c)
            return (true);
    }

    return (false);
}

bool Contains_str(std::string str, std::string to_get)
{
    int validated = 0;

    for (int i = 0; i < str.length(); i++) {
        if ((i + to_get.length()) <= str.length()) {
            for (int j = 0; j < to_get.length(); j++) {
                if (str[i + j] == to_get[j]) {
                    validated++;
                } else {
                    validated = 0;
                }

            }
            if (validated == to_get.length())
                return (true);
        }
    }

    return (false);
}