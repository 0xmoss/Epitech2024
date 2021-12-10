/*
** EPITECH PROJECT, 2020
** strace
** File description:
** main.c
*/

#include "strace.h"

extern pid_t pid_d;

int arguments(int ac, char **argv)
{
    if (ac < 2)
        return (False);
    if (!strcmp(argv[1], "--help"))
        return (False);
    if (!strcmp(argv[1], "-p") && ac > 2)
        return (atoi(argv[2]));
    return (True);
}

static int trace(pid_t pid)
{
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
        return (False);
    pid_d = pid;
    if (trace_process(pid_d) == False)
        return (False);
    return (True);
}

int main(int ac, char **argv)
{
    int check = arguments(ac, argv);

    if (check == False) {
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        return (False);
    }
    return(trace(check));
}
