/*
** EPITECH PROJECT, 2020
** strace
** File description:
** str.c
*/

#include "strace.h"

extern pid_t pid_d;

void sys_str(unsigned long int value)
{
    int i = 0;
    long data = -1;

    printf("\"");
    for (; (char)data != '\0' && i < 42; ++i, ++value) {
        data = ptrace(PTRACE_PEEKDATA, pid_d, value, NULL);
        if (data == -1)
            return;
        sys_char(data);
    }
    printf("\"");
}