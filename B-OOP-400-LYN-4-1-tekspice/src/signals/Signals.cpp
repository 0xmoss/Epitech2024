/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Signals.cpp
*/

#include "Signals.hpp"

#include "Logs.hpp"

void signal_handler_exit(int signal)
{
    Logs logs;

    logs.display("\b\b(CTRL+D)");

    exit(0);
}

void signal_handler_SIGINT(int signal)
{
    Logs logs;

    logs.display("\b\b(CTRL+C)");

    return;
}