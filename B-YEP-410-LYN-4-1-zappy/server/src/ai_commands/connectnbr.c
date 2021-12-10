/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_connectnbr
*/

#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_connectnbr(client_manager *manager, ai_entry *ai)
{
    send_data(ai->data.ai_socket, "%zu\n",
    manager->symdata->teams[ai->data.team_id].max_connected -
    manager->symdata->teams[ai->data.team_id].connected);
}
#pragma GCC diagnostic error "-Wunused-parameter"