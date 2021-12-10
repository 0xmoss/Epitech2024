/*
** EPITECH PROJECT, 2020
** strace
** File description:
** array.c
*/

#include "strace.h"

extern pid_t pid_d;

void sys_array(unsigned long int value)
{
    int i = 0;
    unsigned long_str = -1;

    printf("[");
    for (; (void*)long_str != NULL && i < 6; i++) {
        long_str = ptrace(PTRACE_PEEKDATA, pid_d,value, NULL);
        if (long_str == -1)
            return;
        if (long_str)
            sys_str(long_str);
        value += sizeof(char *);
    }
    printf("]");
    if (i >= 6)
        printf(" ... ");
}