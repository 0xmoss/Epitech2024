/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** phase_startswith.c
*/

#include "phaseout.h"

size_t phase_startswith(char *original, char *start, char end)
{
    if (phase_length(start, end) <= phase_length(original, end)) {
        if (!strncmp(original, start, phase_length(start, end)))
            return (True);
    }

    return (False);
}
