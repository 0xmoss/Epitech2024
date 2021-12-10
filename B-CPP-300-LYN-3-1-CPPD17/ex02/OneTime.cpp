/*
** EPITECH PROJECT, 2019
** OneTime.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "OneTime.hpp"

OneTime::OneTime(std::string key)
{
	this->key = key;
	this->index = 0;
    return;
}

OneTime::~OneTime()
{
    return;
}

int OneTime::get_base(bool decrypt, char c)
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

int OneTime::get_key()
{
    if (this->key[this->index] > 96)
        return (97);
    return (65);
}

void OneTime::encryptChar(char c)
{
	if (isalpha(c)) {
        int base = get_base(false, c);
        int key = get_key();
        
        c -= base + (this->key[this->index] - key);
        c %= 26;
        c += base;
    }
	std::cout << c;
	this->index = ((this->index + 1) % this->key.size());
}

void OneTime::decryptChar(char c)
{
	if (isalpha(c)) {
        int base = get_base(true, c);
        int key = get_key();

        c -= base - (this->key[this->index] - key);
        c %= 26;
        c += base;
    }
	std::cout << c;
	this->index = ((this->index + 1) % this->key.size());
}

void OneTime::reset()
{
	this->index = 0;
}