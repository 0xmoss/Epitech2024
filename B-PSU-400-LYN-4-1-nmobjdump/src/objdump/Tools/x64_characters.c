/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** print_characters.c
*/

#include "tools.h"
#include "align.h"

#include "phaseout.h"

#include "includes.h"

#include "tools.h"

size_t x64_characters_get(unsigned char c)
{
    if (c >= 32 && c <= 126)
        printf("%c", c);
    else
        printf(".");
    return (True);
}

size_t x64_characters_hexa(Elf64_Shdr shdr, char *buffer, size_t i)
{
    for (; i < shdr.sh_size;) {
        printf("%02x", (unsigned char)(buffer + shdr.sh_offset)[i]);
        i++;
        if (modulo(i, 16) == True) {
            printf(S_TAB_2);
            break;
        }
        if (modulo(i, 4) == True)
            printf(S_SPACE);
    }
    if (i >= shdr.sh_size && modulo(i, 16) != True)
        x64_characters_space(i, False);
    return (True);
}

size_t x64_characters_space(size_t i, char end)
{
    if (end == True) {
        for (; modulo(i, 16) == False; i++)
            printf(S_SPACE);
        printf(S_LINE);
        return (True);
    }
    for (; modulo(i, 16) == False;) {
        i++;
        printf(S_TAB_2);
        display(i, 4, S_SPACE);
        display(i, 16, S_SPACE);
    }
    return (True);
}
