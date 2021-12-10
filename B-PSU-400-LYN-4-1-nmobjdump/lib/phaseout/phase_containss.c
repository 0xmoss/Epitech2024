/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "phaseout.h"

size_t phase_containss(char *array, char *check, char end)
{
    size_t valid = 0;
    size_t array_size = phase_length(array, end);
    size_t check_size = phase_length(check, end);

    if (array_size > check_size) {
        for (size_t i = 0; i < (array_size - check_size); i++) {
            for (size_t j = 0; j < check_size; j++) {
                if (array[i + j] == check[j])
                    valid++;
                else
                    valid = 0;
            }
            if (valid > 0)
                return (True);
        }
    }
    return (False);
}
