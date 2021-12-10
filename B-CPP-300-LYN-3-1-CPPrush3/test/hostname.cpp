/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** hostname.cpp
*/

#include "hostname.hpp"

hostname::hostname()
{
    this->host = "_EMPTY_";

    return;
}

hostname::~hostname()
{
    return;
}

std::string hostname::get()
{
    if (this->host == "_EMPTY_") {
        set();
    }

    return (this->host);
}

void hostname::set()
{
    char host[1024];
    gethostname(host, sizeof(host));

    this->host = host;
}

void hostname::display()
{
    std::cout << get() << std::endl;

    return;
}