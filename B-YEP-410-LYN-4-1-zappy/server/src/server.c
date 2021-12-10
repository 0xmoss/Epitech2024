/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** server
*/

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"

static volatile bool is_ok = true;

static void sigint_handler(__attribute__((unused)) int sig)
{
    is_ok = false;
}

static int setup_fd_set(
    client_manager *manager, fd_set *rdfs, int server_socket)
{
    conn_t conn;
    int nfds = server_socket;

    FD_ZERO(rdfs);
    FD_SET(server_socket, rdfs);
    SLIST_FOREACH(conn.ai, &manager->ai_head, entries) {
        if (conn.ai->data.ai_socket > nfds)
            nfds = conn.ai->data.ai_socket;
        FD_SET(conn.ai->data.ai_socket, rdfs);
    }
    SLIST_FOREACH(conn.gui, &manager->gui_head, entries) {
        if (conn.gui->data.gui_socket > nfds)
            nfds = conn.gui->data.gui_socket;
        FD_SET(conn.gui->data.gui_socket, rdfs);
    }
    SLIST_FOREACH(conn.client, &manager->client_head, entries) {
        if (conn.client->data.client_socket > nfds)
            nfds = conn.client->data.client_socket;
        FD_SET(conn.client->data.client_socket, rdfs);
    }
    return nfds + 1;
}

static inline bool kill_all_connections(client_manager *manager)
{
    conn_t conn;

    while (!SLIST_EMPTY(&manager->ai_head)) {
        conn.ai = SLIST_FIRST(&manager->ai_head);
        destroy_ai(manager, conn.ai);
    }
    while (!SLIST_EMPTY(&manager->gui_head)) {
        conn.gui = SLIST_FIRST(&manager->gui_head);
        SLIST_REMOVE_HEAD(&manager->gui_head, entries);
        close(conn.gui->data.gui_socket);
        free(conn.gui);
    }
    while (!SLIST_EMPTY(&manager->client_head)) {
        conn.client = SLIST_FIRST(&manager->client_head);
        SLIST_REMOVE_HEAD(&manager->client_head, entries);
        close(conn.client->data.client_socket);
        free(conn.client);
    }
    return true;
}

bool server_listener(symdata_t *symdata, int server_socket)
{
    struct timespec ts = TIMESPEC_INITIALIZER(symdata->time_unit_reciprocal);
    client_manager manager = CLIENT_MANAGER_INITIALIZER(symdata);
    sigset_t sigmask[2];
    fd_set rdfs;
    int nfds[2];

    if (signal(SIGINT, &sigint_handler) == SIG_ERR)
        return return_error("ERROR: Signal-catching handler failed to init");
    sigemptyset(&sigmask[1]);
    sigaddset(&sigmask[1], SIGINT);
    if (sigprocmask(SIG_BLOCK, &sigmask[1], &sigmask[0]) < 0)
        return return_error("ERROR: Signal-catching mask failed to init");
    while (is_ok)
        if ((nfds[1] = pselect((nfds[0] = setup_fd_set(&manager, &rdfs,
        server_socket)), &rdfs, 0, 0, &ts, &sigmask[0])) < 0)
            is_ok = false;
        else if (nfds[1] > 0)
            fd_switch(&manager, &rdfs, server_socket);
        else if (!SLIST_EMPTY(&manager.ai_head))
            action_switch(&manager);
    return kill_all_connections(&manager);
}