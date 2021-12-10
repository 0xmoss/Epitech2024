/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** func_ptr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = strlen(str) - 1;

    for (; i > 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            tmp[i] = str[i] - 32;
        else
            tmp[i] = str[i];
    }

    printf("%s\n", tmp);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*handler[4])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };
    action_t actions[4] = {PRINT_NORMAL, PRINT_REVERSE, PRINT_UPPER, PRINT_42};

    for (int i = 0; i < 4; i++) {
        if (action == actions[i])
            handler[action](str);
    }
}