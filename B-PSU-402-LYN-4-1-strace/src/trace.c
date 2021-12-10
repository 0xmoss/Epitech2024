/*
** EPITECH PROJECT, 2020
** strace
** File description:
** trace.c
*/

#include "strace.h"

pid_t pid_d = -1;

extern syscalls_t syscalls_d[];

static int instruction(pid_t pid, int *status)
{
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
        return (False);
    if (waitpid(pid, status, 0) == -1)
        return (False);
    return (True);
}

static int analyse_syscall(struct user_regs_struct *user, pid_t pid,
int *status)
{
    unsigned long syscall_number = user->rax;

    if (syscall_number > 313 || syscall_data(syscall_number, user) == False)
        return (False);
    if (syscall_number != 60 && syscall_number != 231) {
        if (syscall_number == 1)
            printf("\n");
        if (instruction(pid, status) == False || ptrace(PTRACE_GETREGS, pid, NULL, user) == -1)
            return (False);
    }
    return_value(syscall_number, syscalls_d[syscall_number].return_t, user);
    if (syscall_number == 60 || syscall_number == 231) {
        printf("\n+++ exited with ");
        system("echo -n $?");
        printf(" +++\n");
        exit(True);
    }

    return (True);
}

static int analyse_user(struct user_regs_struct *user, pid_t pid, int *status)
{
    long ptrace_d = ptrace(PTRACE_PEEKDATA, pid, user->rip, NULL);

    if (ptrace_d == -1)
        return (False);
    ptrace_d &= 0xffff;
    if (ptrace_d == 0x050f) {
        if (analyse_syscall(user, pid, status) == False)
            return (False);
    }
    return (True);
}

int trace_process(pid_t pid)
{
    struct user_regs_struct user;
    int status;
    size_t launched = True;

    if (waitpid(pid, &status, 0) == -1)
        return (False);
    while (launched == True) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &user) == -1)
            return (False);
        if (analyse_user(&user, pid, &status) == False)
            return (False);
        if (instruction(pid, &status) == False)
            return (False);
    }
}
