/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** flags.h
*/

#include "phaseout.h"

#include "includes.h"

#ifndef FLAGS_H
    #define FLAGS_H

    #define BFD_NO_FLAGS    0x00
    #define HAS_RELOC       0x01
    #define EXEC_P          0x02
    #define HAS_LINENO      0x04
    #define HAS_DEBUG       0x08
    #define HAS_SYMS        0x10
    #define HAS_LOCALS      0x20
    #define HAS_DYNAMIC     0x40
    #define WP_TEXT         0x80
    #define D_PAGED         0x100    

#endif /* FLAGS_H */

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    typedef struct flag_s
    {
        int (*ptr)(int flags);
    } flags_t;

    int check_bfd_no_flags(int);
    int check_has_reloc(int);
    int check_exec_p(int);
    int check_has_lineno(int);
    int check_has_debug(int);
    int check_has_syms(int);
    int check_has_locals(int);
    int check_has_dynamic(int);
    int check_wp_text(int);
    int check_d_paged(int);

#endif /* FUNCTIONS_H */

#ifndef CHECK_FLAGS_H
    #define CHECK_FLAGS_H

    int x64_flags_display(int);
    int x64_flags_check(Elf64_Ehdr *, Elf64_Shdr *, int);

    int x32_flags_display(int);
    int x32_flags_check(Elf32_Ehdr *, Elf32_Shdr *, int);

#endif /* CHECK_FLAGS_H */
