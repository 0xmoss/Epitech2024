/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** main.c
*/

#include "menger.h"

int main(int ac, char **argv)
{
    if (ac != 3)
        return (84);
    return (menger(atoi(argv[1]), atoi(argv[2])));
}