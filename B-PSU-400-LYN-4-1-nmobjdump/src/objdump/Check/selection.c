/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** selection.c
*/

#include "phaseout.h"
#include "selection.h"

#include "includes.h"

size_t check_selection(char *string)
{
    if (string[0] != '\0' &&
        strcmp(string, ".strtab")  != 0 &&
        phase_containss(string, ".rela\0", EMPTY) != True &&
        phase_containss(string, ".note\0", EMPTY) != True &&
        strcmp(string, ".symtab")  != 0) {
            return (True);
    }
    return (False);
}
