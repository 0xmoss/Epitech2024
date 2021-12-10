/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** tab_to2dtab.c
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **tmp = malloc(sizeof(int *) * length);
    int index = 0;

    for (int i = 0; i < length; i++) {
        tmp[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            tmp[i][j] = tab[index];
            index++;
        }
    }
    *res = tmp;
}
