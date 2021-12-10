/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** command
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include "struct.h"
#include "prototypes.h"
#include "extern.h"

static bool check_data(void *data, size_t size, request_data *request)
{
    uuid_t tmp;
    const char *cast = data;

    if (!strcmp(data, ""))
        return false;
    for (size_t i = 0; cast[i] != '\0' && i < size; ++i)
        if (!isprint(cast[i]))
            return false;
    if ((data == request->uuid0 || data == request->uuid1 ||
        data == request->uuid2) && uuid_parse(data, tmp) == -1)
            return false;
    return true;
}

static void recv_data(
    struct client_entry *client,
    void *data, size_t size, request_data *request)
{
    if (request->info == BAD_REQUEST)
        return;
    if (recv(client->data.client_socket, data, size, 0) != (ssize_t) size)
            request->info = BAD_REQUEST;
    if (check_data(data, size, request) == false)
        request->info = BAD_REQUEST;
}

request_data parse_request(struct client_entry *client, request_data *data)
{
    recv_data(client, data->command, MAX_COMMAND_LENGTH, data);
    if (data->info & UUID0)
        recv_data(client, data->uuid0, MAX_UUID_LENGTH, data);
    if (data->info & UUID1)
        recv_data(client, data->uuid1, MAX_UUID_LENGTH, data);
    if (data->info & UUID2)
        recv_data(client, data->uuid2, MAX_UUID_LENGTH, data);
    if (data->info & NAME)
        recv_data(client, data->name, MAX_NAME_LENGTH, data);
    if (data->info & DESCRIPTION)
        recv_data(client, data->description, MAX_DESCRIPTION_LENGTH, data);
    if (data->info & BODY)
        recv_data(client, data->body, MAX_BODY_LENGTH, data);
    return *data;
}

response_data execute_request(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    bool found = false;
    response_data resp;

    for (size_t i = 0; i < COMMANDS_NUMBER; ++i) {
        if (strcmp(data->command, COMMAND_NAMES[i]))
            continue;
        if (COMMAND_AUTH_REQUIRE[i]) {
            resp = client->data.user ? COMMAND_FUNCS[i](manager, client, data)
            : create_response(KO,
            "You need to be logged in to use this command.");
            found = true;
            break;
        } else {
            resp = COMMAND_FUNCS[i](manager, client, data);
            found = true;
            break;
        }
    }
    if (found == false)
        create_response(UNKNOWN_COMMAND, "Unknown Command.");
    return resp;
}