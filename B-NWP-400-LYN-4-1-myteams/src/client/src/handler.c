/*
** EPITECH PROJECT, 2020
** teams
** File description:
** handler.c
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

size_t id(char *function_name)
{
    char *ids = phase_set("help|login|logout|users|user|send|messages|subscribe|subscribed|unsubscribe|use|create|list|info\0", EMPTY);
    char **ids_d = phase_split(ids, '|', EMPTY, NULL);

    for (size_t i = 0; ids_d[i] != NULL; i++) {
        if (phase_startswith(function_name, ids_d[i], EMPTY) == True)
            return (i);
    }

    return (0);
}

request_data *handler(self_t *self, request_data *data)
{
    commands_t list[] = {
        {cli_help},
        {cli_login},
        {cli_logout},
        {cli_users},
        {cli_user},
        {cli_send},
        {cli_messages},
        {cli_subscribe},
        {cli_subscribed},
        {cli_unsubscribed},
        {cli_use},
        {cli_create},
        {cli_list},
        {cli_info}
    };

    return (list[id(self->command)].command(self, data));
}

void recv_handler(self_t *self, response_data data)
{
    recv_commands_t list[] = {
        {recv_help},
        {recv_login},
        {recv_logout},
        {recv_users},
        {recv_user},
        {recv_send},
        {recv_messages},
        {recv_subscribe},
        {recv_subscribed},
        {recv_unsubscribe},
        {recv_use},
        {recv_create},
        {recv_list},
        {recv_info}
    };

    list[id(self->command)].command(self, data);
}
