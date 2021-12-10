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
#include "os.hpp"
#include "hostname.hpp"

int main(int ac, char **argv)
{
    date current_date;
    errors current_errors;
    username user;
    hostname host;
    os OS;

    if (ac < 2) {
        return (current_errors.display(1, "Missing mod type"));
    }
    window win;
    current_date.display();
    user.display();
    host.display();
    OS.display();
    win.start();
    return (0);
}
