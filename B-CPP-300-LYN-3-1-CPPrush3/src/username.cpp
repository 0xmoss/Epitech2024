/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** username.cpp
*/

#include "username.hpp"

nameInfo::nameInfo()
{
    setHostname();
    setUsername();
    this->_activate_module = false;
}

nameInfo::~nameInfo()
{
}

void nameInfo::setUsername()
{
    std::string username = getenv("USER");
    if (username == "")
        this->_username_ = "_EROOR_";
    else
        this->_username_ = username;
}

void nameInfo::setHostname()
{
    std::ifstream file("/proc/sys/kernel/hostname");
    std::string hostname = "_ERROR_";

    if (!file)
        this->_hostname_ = hostname;
    else
        getline(file, hostname);
    this->_hostname_ = hostname;
    file.close();
}

void nameInfo::setActivate(bool choice)
{
    this->_activate_module = choice;
}


void nameInfo::display()
{
    std::cout << "Module Activated : "<< ((getActivate()) ? "true" : "false")<< "\tUsername : " << getUsername() << "\tHostname : " << getHostname() << std::endl;

    return;
}