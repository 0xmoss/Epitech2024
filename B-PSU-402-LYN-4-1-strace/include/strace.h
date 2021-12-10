/*
** EPITECH PROJECT, 2020
** strace
** File description:
** strace.h
*/

#ifndef STRACE_H_
    #define STRACE_H_

    #include <err.h>
    #include <errno.h>
    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/ptrace.h>
    #include <sys/types.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <unistd.h>

    // BOOLEAN
    #define True  1
    #define False 0
    #define Error 84

    typedef struct syscalls_s
    {
        char *name;
        int parameters_c;
        char * parameters[6];
        char *return_t;
    } syscalls_t;

    typedef struct types_s
    {
        char *name;
        void (*sys_call)(unsigned long int register_value);
    } types_t;

    void handle_exit(int *);
    int launch_child(char **);

    void strace(int, struct user_regs_struct *);
    void return_value(int, char *, struct user_regs_struct *);
    int syscall_data(int, struct user_regs_struct *);

    void sys_int(unsigned long int);
    void sys_char(char);
    void sys_long(unsigned long int);
    void sys_uint(unsigned long int);
    void sys_ulong(unsigned long int);
    void sys_ptr(unsigned long int);
    void sys_str(unsigned long int);
    void sys_array(unsigned long int);
    void sys_unknown(unsigned long int);
    void sys_void(unsigned long int);

    unsigned long int registry(int, struct user_regs_struct *);

    int trace_process(pid_t);

    syscalls_t *get_prototypes(void);
    types_t *get_types(void);

    int arguments(int, char **);

#endif /* STRACE_H_ */
