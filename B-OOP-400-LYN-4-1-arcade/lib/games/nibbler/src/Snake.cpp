/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

Snake::Snake():_size(4), _speed(1)
{
    std::cout << "Create snake" << std::endl;
}

Snake::~Snake()
{
}

int Snake::getSize()
{
    return (this->_size);
}

int Snake::getSpeed()
{
    return (this->_speed);
}

int *Snake::getPos()
{
    return(this->_pos);
}
void Snake::eat()
{
    this->_size++;
}