/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** build.c
*/

#include "nm.h"

void build(int ac, void *data, char *filename, long size)
{
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    int tc = 0;
    char **splitted = phase_split(filename, '/', EMPTY, NULL);
    char *binary = splitted[phase_llength(splitted, NULL) - 1];

    ehdr = (Elf64_Ehdr*)data;
    if (elf(ehdr, filename) != -1) {
        shdr = (Elf64_Shdr*)((char*)data + ehdr->e_shoff);
        tc = trucated(ehdr, shdr, size);
        if (tc) {
            if (tc == -1)
                printf("%s: %s: File truncated\n", binary, filename);
            else
                printf("%s: %s: File format not recognized\n", binary, filename);
        }
        if (display(ac, ehdr, shdr, data, filename) == -1)
            printf("%s: %s: %s\n", binary, filename, "no symbols");
    }
}
