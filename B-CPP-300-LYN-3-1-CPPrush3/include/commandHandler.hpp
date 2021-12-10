/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** commandHandler.hpp
*/

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "main.hpp"
#include "monitorcore.hpp"

class Command
{
    public:
        Command();
        ~Command();
        int helpCommand(int argc, char **argv);
        int parsingCommand(int argc, char **argv,MonitorCore &monitor);
};

#endif