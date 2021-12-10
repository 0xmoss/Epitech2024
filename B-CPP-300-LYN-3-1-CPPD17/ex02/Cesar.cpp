/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD17-
** File description:
** Cesar.cpp
*/

#include <iostream>

#include "Cesar.hpp"

Cesar::Cesar()
{
	reset();
    return;
}

Cesar::~Cesar()
{
    return;
}

int Cesar::get_value(bool decrypt, char c)
{
    if (decrypt == false) {
        if (c > 96)
            return (97);
        return (65);
    }
    if (c > 96)
        return (122);
    return (90);
}

void Cesar::encryptChar(char c)
{
	if (isalpha(c)) {
        int value = get_value(false, c);

        c = (c - value + this->decal);
        c %= 26;
        c += value;
    }
	this->decal++;
    this->decal %= 26;
	std::cout << c;
}

void Cesar::decryptChar(char c)
{
	if (isalpha(c)) {
        int value = get_value(true, c);

        c = (c - value - this->decal);
        c %= 26;
        c += value;
    }
	this->decal++;
    this->decal %= 26;
	std::cout << c;
}

void Cesar::reset()
{
	decal = 3;
    return;
}
