/*
** EPITECH PROJECT, 2020
** strace
** File description:
** syscall_datas.c
*/

#include "strace.h"

#include "syscall.h"

extern syscalls_t syscalls_d[];
extern types_t types_d[];

unsigned long int registry(int count, struct user_regs_struct *user)
{
    if (rax(count, user) != 84)
        return (rax(count, user));
    if (rdi(count, user) != 84)
        return (rdi(count, user));
    if (rsi(count, user) != 84)
        return (rsi(count, user));
    if (rdx(count, user) != 84)
        return (rdx(count, user));
    if (rcx(count, user) != 84)
        return (rcx(count, user));
    if (r8(count, user) != 84)
        return (r8(count, user));
    if (r9(count, user) != 84)
        return (r9(count, user));

    return (0);
}

void register_data(char *type, int count, struct user_regs_struct *user)
{
    int i = 0;

    if (type[strlen(type) - 1] == '*' && strcmp(type, "char *") &&
    strcmp(type, "char **"))
        sys_ptr(registry(count, user));
    else {
        for (; types_d[i + 1].name != NULL && strcmp(types_d[i].name, type);
        ++i);
            types_d[i].sys_call(registry(count, user));
    }
}

void return_value(int syscall, char *type, struct user_regs_struct *user)
{
    printf(") = ");
    if (syscall != 60 && syscall != 231) {
        if ((long)user->rax < 0)
            printf("-1 (%llu)", -user->rax);
        else
            register_data(type, -1, user);
    } else
        printf("?");
    printf("\n");
}

void strace(int syscall, struct user_regs_struct *user)
{
    int i = 0;

    for (; i < syscalls_d[syscall].parameters_c - 1; ++i) {
        register_data(syscalls_d[syscall].parameters[i], i, user);
        printf(", ");
    }
    register_data(syscalls_d[syscall].parameters[i], i, user);
}

int syscall_data(int syscall, struct user_regs_struct *user)
{
    printf("%s(", syscalls_d[syscall].name);
    strace(syscall, user);

    return (True);
}