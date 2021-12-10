/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** server
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/select.h>
#include <string.h>
#include <unistd.h>
#include "struct.h"
#include "prototypes.h"
#include "extern.h"

static int setup_fd_set(
    client_manager *manager, fd_set *rdfs, int server_socket)
{
    struct client_entry *client;
    int higher_socket_fd = server_socket > global_eventfd ?
    server_socket : global_eventfd;

    FD_ZERO(rdfs);
    FD_SET(server_socket, rdfs);
    FD_SET(global_eventfd, rdfs);
    SLIST_FOREACH(client, &manager->client_head, entries) {
        if (client->data.client_socket > higher_socket_fd)
            higher_socket_fd = client->data.client_socket;
        FD_SET(client->data.client_socket, rdfs);
    }
    return higher_socket_fd;
}

static void fd_handle_client(
    client_manager *manager, struct client_entry *client, fd_set *rdfs)
{
    unsigned char info;
    request_data request;
    response_data response;

    if (!FD_ISSET(client->data.client_socket, rdfs))
        return;
    memset(&request, 0, sizeof(request));
    if (read(client->data.client_socket, &info, sizeof(info)) > 0) {
        request.info = info;
        request = parse_request(client, &request);
        if (request.info != BAD_REQUEST)
            response = execute_request(manager, client, &request);
        else
            response = create_response(INVALID_REQUEST, "Invalid Request.");
        send_data_to_client(client, response, true);
    } else {
        SLIST_REMOVE(&manager->client_head, client, client_entry, entries);
        delete_client(client);
    }
}

static void fd_switch(
    client_manager *manager, fd_set *rdfs, int server_socket, bool *is_ok)
{
    struct client_entry *client;

    if (FD_ISSET(global_eventfd, rdfs)) {
        *is_ok = false;
    } else if (FD_ISSET(server_socket, rdfs)) {
        client = new_client(server_socket);
        SLIST_INSERT_HEAD(&manager->client_head, client, entries);
    } else {
        SLIST_FOREACH(client, &manager->client_head, entries)
            fd_handle_client(manager, client, rdfs);
    }
}

void teams_server(int server_socket)
{
    fd_set rdfs;
    bool is_ok = true;
    int higher_socket_fd;
    client_manager manager = load_manager();

    while (is_ok) {
        higher_socket_fd = setup_fd_set(&manager, &rdfs, server_socket);
        if (select(higher_socket_fd + 1, &rdfs, NULL, NULL, NULL) == -1) {
            is_ok = false;
        } else {
            fd_switch(&manager, &rdfs, server_socket, &is_ok);
        }
    }
    dump_manager(&manager);
    unload_manager(&manager);
}