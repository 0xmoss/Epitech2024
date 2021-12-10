/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** ScoreBoard.cpp
*/

#include "ScoreBoard.hpp"

ScoreBoard::ScoreBoard():_score(0), _life(3), _time(0)
{
}

ScoreBoard::~ScoreBoard()
{
}

int ScoreBoard::getTime()
{
    return (this->_time);
}

void ScoreBoard::newTime()
{
    this->_time++;
}

int ScoreBoard::getScore()
{
    return (this->_score);
}

int ScoreBoard::getLife()
{
    return (this->_life);
}