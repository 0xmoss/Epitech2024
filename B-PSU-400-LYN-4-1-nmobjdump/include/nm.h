/*
** EPITECH PROJECT, 2020
** nm
** File description:
** nm.h
*/

#ifndef OBJDUMP_H
       #define OBJDUMP_H

       #include <stdio.h>
       #include <elf.h>
       #include <stdint.h>
       #include <ctype.h>
       #include <stdlib.h>
       #include <string.h>
       #include <fcntl.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <sys/mman.h>

       #include "phaseout.h"

       #define default_binary "a.out"

       int nm(int, char *);

       // TOOLS
       void *load(char *, int *, long *);
       int  selection(Elf64_Shdr *, int);
       int  trucated(Elf64_Ehdr *, Elf64_Shdr *, long);

       // ARCHITECTURE
       void build(int, void *, char *, long);
       int elf(Elf64_Ehdr *, char *);
       int dump(Elf64_Sym *, long int, Elf64_Shdr *, unsigned char *);
       int display(int, Elf64_Ehdr *, Elf64_Shdr *, void *, char *);

       // SYMBOLS
       char sym_get(Elf64_Sym *, Elf64_Shdr *);
       char sym_array(Elf64_Sym *, Elf64_Shdr *);
       char sym_code(Elf64_Sym *, Elf64_Shdr *);
       char sym_shrug(Elf64_Sym *);
       char sym_data(Elf64_Sym *, Elf64_Shdr *);

#endif /* OBJDUMP_H */
