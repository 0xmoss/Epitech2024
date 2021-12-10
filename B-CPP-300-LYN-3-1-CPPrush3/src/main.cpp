/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** main.cpp
*/

#include "errors.hpp"
#include "engine.hpp"
#include "username.hpp"
#include "date.hpp"
#include "window.hpp"
#include "systemInfo.hpp"
#include "nCurses.hpp"
#include "monitorcore.hpp"
#include "commandHandler.hpp"
#include "network.hpp"

int main(int ac, char **argv)
{
    MonitorCore core;
    Command command;

    if (command.parsingCommand(ac, argv, core) == 1)
        return 1;
    if (strcmp(argv[1], "gui") == 0) {
        window win(&core);
        win.start();
    } else if (strcmp(argv[1], "cli") == 0) {
        nCurses ncu(&core);
        ncu.start();
    }

    return (0);
}