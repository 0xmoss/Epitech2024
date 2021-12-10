/*
** EPITECH PROJECT, 2020
** teams
** File description:
** main.c
*/

#include "client.h"

int main(int ac, char **av)
{
    int status = 84;

    if (ac == 2 && strcmp(av[1], "-help"))
        status = 0;
    else if (ac == 3) {
        if (atoi(av[2]) >= 0) {
            if (atoi(av[2]) >= 1 && atoi(av[2]) <= 65534) {
                launch(av[1], atoi(av[2]));
                return (0);
            }
        } else {
            printf("invalid port\n");
            return (84);
        }
    }

    return (help(status));
}
