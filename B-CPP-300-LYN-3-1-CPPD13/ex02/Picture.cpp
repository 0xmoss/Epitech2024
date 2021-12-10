/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Picture.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Picture.hpp"

Picture::Picture() : data("")
{
    return;
}

Picture::Picture(const std::string &name)
{
    getPictureFromFile(name);
    return;
}

Picture::~Picture()
{
    return;
}

bool Picture::getPictureFromFile(const std::string &name)
{
    std::ifstream stream(name.data());
    std::stringstream buffer;

    if (stream.is_open()) {
        buffer << stream.rdbuf();
        this->data = buffer.str();
        return (true);
    }
    this->data = "ERROR";
    return(false);
    
}

Picture &Picture::operator = (Picture const &content)
{
    this->data = content.data;
    return (*this);
}