/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** menger.c
*/

#include "menger.h"

void display(int s, int x, int y)
{
    printf("%.3d %.3d %.3d\n", s, x, y);
}

int menger(int s, int level)
{
    if (level < s)
        return (engine(s, 0, 0, level));
    return (-1);
}

int engine(int s, int x, int y, int level)
{
    if (s >= 3 && level > 0) {
        s /= 3;
        level--;
        display(s, s + x, s + y);
        engine(s, x, y, level);
        engine(s, x, y + s, level);
        engine(s, x, y + 2 * s, level);
        engine(s, x + s, y, level);
        engine(s, x + s, y + 2 * s, level);
        engine(s, x + 2 * s, y, level);
        engine(s, x + 2 * s, y + s, level);
        engine(s, x + 2 * s, y + 2 * s, level);
    }
    return (0);
}