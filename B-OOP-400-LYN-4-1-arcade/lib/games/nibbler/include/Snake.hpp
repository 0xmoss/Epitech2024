/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** Snake.hpp
*/

#pragma once

#include <iostream>
#include <string>

class Snake{
    public :
        Snake();
        ~Snake();
        int getSpeed();
        int getSize();
        int *getPos();
        void eat();
    protected:
        int _size;
        int _speed;
        int *_pos;
};