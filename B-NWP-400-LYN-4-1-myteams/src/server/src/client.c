/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** client
*/

/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-alexandre.monier [WSL: Ubuntu]
** File description:
** client
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "struct.h"
#include "logging_server.h"

struct client_entry *new_client(int server_socket)
{
    struct client_entry *client;
    int socket_fd = accept(server_socket, NULL, NULL);

    if (socket_fd < 0)
        return NULL;
    client = malloc(sizeof(struct client_entry));
    client->data.client_socket = socket_fd;
    client->data.user = NULL;
    client->data.team = NULL;
    client->data.channel = NULL;
    client->data.thread = NULL;
    return client;
}

void delete_client(struct client_entry *client)
{
    char uuid[UUID_STR_LEN] = {0};

    if (client == NULL)
        return;
    if (client->data.client_socket != -1) {
        close(client->data.client_socket);
    }
    if (client->data.user != NULL) {
        client->data.user->data.connected = false;
        uuid_unparse(client->data.user->data.uuid, uuid);
        server_event_user_logged_out(uuid);
    }
    free(client);
}

struct user_entry *find_user_by_name(
    client_manager *manager, const char *name)
{
    struct user_entry *user = NULL;
    struct user_entry *user_cursor = NULL;

    SLIST_FOREACH(user_cursor, &manager->user_head, entries) {
        if (!strcmp(user_cursor->data.name, name)) {
            user = user_cursor;
            break;
        }
    }
    return user;
}

struct client_entry *find_client_by_name(
    client_manager *manager, const char *name)
{
    struct client_entry *client = NULL;
    struct client_entry *client_cursor = NULL;

    SLIST_FOREACH(client_cursor, &manager->client_head, entries) {
        if (client_cursor->data.user == NULL)
            continue;
        if (!strcmp(client_cursor->data.user->data.name, name)) {
            client = client_cursor;
            break;
        }
    }
    return client;
}

struct client_entry *find_client_by_uuid(client_manager *manager, uuid_t uuid)
{
    struct client_entry *client = NULL;
    struct client_entry *client_cursor = NULL;

    SLIST_FOREACH(client_cursor, &manager->client_head, entries) {
        if (client_cursor->data.user == NULL)
            continue;
        if (!uuid_compare(client_cursor->data.user->data.uuid, uuid)) {
            client = client_cursor;
            break;
        }
    }
    return client;
}