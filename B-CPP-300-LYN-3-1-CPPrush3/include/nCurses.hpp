/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "main.hpp"
#include "IMonitorDisplay.hpp"

class nCurses : public IMonitorDisplay
{
    private:

    public:
        nCurses(MonitorCore *core);
        ~nCurses();
        void start();
        bool key();
        void printUser();
        void printTime();
        void printSys();
        void printRam();
        void printCPU();
        void printNet();

};
#endif /* !NCURSES_HPP_ */
