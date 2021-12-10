/*
** EPITECH PROJECT, 2020
** strace
** File description:
** display.h
*/

#include "strace.h"

#ifndef DISPLAY_H
    #define DISPLAY_H

    // REGISTRY
    unsigned long int rax(int, struct user_regs_struct *);
    unsigned long int rdi(int, struct user_regs_struct *);
    unsigned long int rsi(int, struct user_regs_struct *);
    unsigned long int rdx(int, struct user_regs_struct *);
    unsigned long int rcx(int, struct user_regs_struct *);
    unsigned long int r8(int, struct user_regs_struct *);
    unsigned long int r9(int, struct user_regs_struct *);

#endif /* DISPLAY_H */
