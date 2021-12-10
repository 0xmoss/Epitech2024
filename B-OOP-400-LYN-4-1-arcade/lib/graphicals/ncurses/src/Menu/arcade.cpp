/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "arcade.hpp"

#include <ncurses.h>
#include <vector>
#include "vectors.hpp"

void Libraries()
{
    std::vector<std::string> libraries_list = {
        "0: ncurses",
        "1: sdl2",
        "2: sfml"
    };

    /*
    for (auto i = libraries_list.begin(); i != libraries_list.end(); i++) {
        printw(++i);
        printw("\n");
    }
    */
}

int Library()
{
    std::string input;
    int data = getch();

    std::cout << data << std::endl;
    return (data);
}

void Display(void)
{
    initscr();
    printw("Enter the library to start your game with:\n");
    refresh();
    Libraries();
    Library();
    endwin();
}
