/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

std::string Arms::serial()
{
    return(this->_serial);
}

bool Arms::getFunctionnal()
{
    return(this->_functionnal);
}

void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << this->_serial <<
    " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

std::string Legs::serial()
{
    return(this->_serial);
}

bool Legs::getFunctionnal()
{
    return(this->_functionnal);
}

void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << this->_serial <<
    " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}

// Head

Head::Head(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

std::string Head::serial()
{
    return(this->_serial);
}

bool Head::getFunctionnal()
{
    return(this->_functionnal);
}

void Head::informations()
{
    std::cout << "\t[Parts] Head " << this->_serial <<
    " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}