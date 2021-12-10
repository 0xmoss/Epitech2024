/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** RAM.cpp
*/

#include "RAM.hpp"
#include <sys/sysinfo.h>

RAM::RAM()
{
    this->setRam();
    this->_activate_module = false;
}

RAM::~RAM()
{
}

float RAM::getTotal()
{
    this->setRam();
    return _total_ram_;
}

void RAM::setActivate(bool choice)
{
    this->_activate_module = choice;
}

void RAM::setRam()
{
    struct sysinfo sys;
    sysinfo (&sys);

    this->_total_ram_ = (float)sys.totalram / (1024 * 1024 * 1024);
    this->_available_ram_ = (float)sys.freeram / (1024 * 1024 * 1024);
    this->_used_ram_ = this->_total_ram_ - this->_available_ram_;
}

void RAM::display()
{
    std::cout << this->getTotal() << "\tused :" << this->getUsed() << "\tavailable : " << this->getAvailable() << std::endl;
}

