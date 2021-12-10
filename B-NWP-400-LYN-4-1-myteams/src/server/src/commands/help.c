/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** help
*/

#include <string.h>
#include "extern.h"
#include "struct.h"
#include "prototypes.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
response_data help_command(
    client_manager *manager, struct client_entry *client, request_data *data)
{
    return create_response(OK, HELP_COMMAND);
}
#pragma GCC diagnostic error "-Wunused-parameter"