/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** main
*/

#include "abstractvm.hpp"
#include "checker.hpp"

int main(int ac, char **argv)
{
    checker checker;
    abstractvm abstractvm;

    if (ac > 1) {
        for (int i = 1; i < ac; i++) {
            abstractvm.path = std::string(argv[i]);
            checker.check(abstractvm.path);
            abstractvm.open();
        }
        return (0);
    }
    if (abstractvm.parser() == true)
        return (0);
    return (84);
}
