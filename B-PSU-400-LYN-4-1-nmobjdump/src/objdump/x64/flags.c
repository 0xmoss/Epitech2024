/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** flags.c
*/

#include "phaseout.h"

#include "flags.h"
#include "includes.h"

int x64_flags_display(int flags)
{
    int tmp = 0;
    flags_t handler[10] = {
        { &check_bfd_no_flags },
        { &check_d_paged },
        { &check_exec_p },
        { &check_has_debug },
        { &check_has_dynamic },
        { &check_has_lineno },
        { &check_has_locals },
        { &check_has_reloc },
        { &check_has_syms },
        { &check_wp_text }
    };

    for (int i = 0; i < 10; i++) {
        tmp = flags;
        flags = handler[i].ptr(flags);
        if (i != 0 && flags != 0 && flags != tmp)
            printf(", ");
    }
    return (True);
}

int x64_flags_check(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, int flags)
{
    if (ehdr->e_type == ET_EXEC)
        flags += EXEC_P + D_PAGED;
    else if (ehdr->e_type == ET_DYN)
        flags += HAS_DYNAMIC + D_PAGED;
    else if (ehdr->e_type == ET_REL)
        flags += HAS_RELOC;
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            flags += HAS_SYMS;
        if (shdr[i].sh_type == SHT_DYNAMIC)
            flags += HAS_DYNAMIC;
    }
    return (flags);
}
