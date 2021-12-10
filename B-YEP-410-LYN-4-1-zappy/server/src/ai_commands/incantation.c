/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_incantation
*/

#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_incantation(client_manager *manager, ai_entry *ai)
{
    if (generate_incantation(manager->symdata, ai, false)) {
        send_data(ai->data.ai_socket, "Current level: %zu", ai->data.elevation);
        send_data_to_gui(manager, "plv %zu %zu\n", ai->data.number, ai->data.elevation);
        send_data_to_gui(manager, "pie %zd %zd %zu\n", ai->data.pos.x, ai->data.pos.y, ai->data.elevation);
        send_data_to_gui(manager, "pin %zu %zu %zu %zu %zu %zu %zu %zu %zu %zu\n", ai->data.number, ai->data.pos.x, ai->data.pos.y,
        ai->data.inventory.food, ai->data.inventory.linemate, ai->data.inventory.deraumere, ai->data.inventory.sibur,
        ai->data.inventory.mendiane, ai->data.inventory.phiras, ai->data.inventory.thystame);
    } else {
        send(ai->data.ai_socket, "ko\n", 3, 0);
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"