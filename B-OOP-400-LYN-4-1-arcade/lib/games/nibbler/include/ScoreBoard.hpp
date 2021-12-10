/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** ScoreBoard.hpp
*/

#pragma once

#include <iostream>
#include <string>

class ScoreBoard{
    public:
        ScoreBoard();
        ~ScoreBoard();
        int getScore();
        int getLife();
        int getTime();
        void newTime();
    protected:
        int _score;
        int _time;
        int _life;
};