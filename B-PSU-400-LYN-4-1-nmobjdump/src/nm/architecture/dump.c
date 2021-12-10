/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** dump.c
*/

#include "nm.h"

int dump(
    Elf64_Sym *symTab,
    long int size,
    Elf64_Shdr *shdr,
    unsigned char *strtab
)
{
    Elf64_Sym symbol;
    char charSymbol;
    char *empty = phase_set("                 ", EMPTY);

    for (int i = 0; i < size; i++) {
        symbol = symTab[i];
        if (symbol.st_info != STT_FILE && symbol.st_name != 0) {
            charSymbol = sym_get(&symbol, shdr);
            if ((unsigned int)symbol.st_value == 0 && (charSymbol == 'w' || charSymbol == 'U'))
                printf("%s", empty);
            else
                printf("%016x ", (unsigned int)symbol.st_value);
            printf("%c %s\n", sym_get(&symbol, shdr), &strtab[symbol.st_name]);
        }
    }

    return (0);
}
