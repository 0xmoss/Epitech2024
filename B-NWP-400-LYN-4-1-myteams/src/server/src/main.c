/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/eventfd.h>
#include "prototypes.h"
#include "const.h"
#include "global.h"

static inline void print_usage(char const *executable)
{
    printf("USAGE:\t%s port\n\n\t"
        "port\tis the port number on which the server socket listens.",
        executable);
}

static inline bool check_args(char **argv)
{
    char *endptr;
    long tmp_port = strtoul(argv[1], &endptr, 10);

    return !(endptr == argv[1] || tmp_port < 0 || tmp_port > 65535);
}

static inline u_int16_t parse_args(char **argv)
{
    return atoi(argv[1]);
}

void sigint_handler(__attribute__((unused)) int signum)
{
    const uint64_t click = 1;
    ssize_t __attribute__((unused)) ret;

    ret = write(global_eventfd, &click, sizeof(click));
}

int main(int argc, char **argv)
{
    u_int16_t port;
    int server_socket;

    if (argc != 2) {
        print_usage(argv[0]);
        return 84;
    } else if (check_args(argv)) {
        global_eventfd = eventfd(0, 0);
        if (global_eventfd == -1)
            return 84;
        signal(SIGINT, sigint_handler);
        port = parse_args(argv);
        server_socket = init_server(port);
        teams_server(server_socket);
        close(global_eventfd);
        close(server_socket);
    } else {
        printf("Invalid arguments.\n");
        return 84;
    }
    return 0;
}