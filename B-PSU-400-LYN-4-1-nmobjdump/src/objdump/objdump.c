/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** objdump.c
*/

#include "check.h"
#include "open.h"
#include "flags.h"

#include "phaseout.h"

int main(int ac, char **argv)
{
    int fd = 0;

    if (check_arguments(ac, argv) == False)
        return (84);
    fd = x64_open_file(argv[1]);
    close(fd);
    return (0);
}
