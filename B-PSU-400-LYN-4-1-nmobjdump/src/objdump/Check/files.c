/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** files.c
*/

#include "phaseout.h"
#include "check.h"
#include "includes.h"

size_t check_extension(char *file)
{
    char *extensions = phase_set("txt|o|out|a", EMPTY);
    char **data = phase_split(extensions, '|', EMPTY, NULL);
    size_t data_size = phase_llength(data, NULL);
    size_t result = 0;

    for (size_t i = 0; i < data_size; i++) {
        result = phase_extension(file, data[i], EMPTY);
        if (result != False) {
            free(extensions);
            phase_ffree(data, NULL);
            return (True);
        }
    }
    free(extensions);
    phase_ffree(data, NULL);
    return (False);
}

size_t check_arguments(int ac, char **argv)
{
    if (ac <= 1) {
        printf("Usage: ./my_objdump <file>\n");
        return (False);
    }
    for (int i = 1; i < ac; i++) {
        if (check_extension(argv[i]) == True) {
            if (access(argv[i], F_OK) != 0) {
                printf("%s: File not found\n", argv[i]);
                return (False);
            }
        } else {
            printf("%s: File extension not supported yet\n", argv[i]);
            return (False);
        }
    }
    return (True);
}
