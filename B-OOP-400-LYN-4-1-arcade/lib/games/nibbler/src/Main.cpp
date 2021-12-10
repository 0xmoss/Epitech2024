/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** Main.cpp
*/


#include <iostream>
#include <string>
#include <unistd.h>
#include "ScoreBoard.hpp"
#include "Snake.hpp"

int main(void)
{
    Snake snake1;
    ScoreBoard board;

    while (board.getLife() != 0) {
        std::cout << "Score :" << board.getScore() << std::endl;
        std::cout << "Time :" << board.getTime() << std::endl;
        std::cout << "Size :" << snake1.getSize() << std::endl;
        if (board.getTime() % 5 == 0)
            snake1.eat();
        board.newTime();
        sleep(1);
        std::cout << "-----" << std::endl;
    }

    return (0);
}