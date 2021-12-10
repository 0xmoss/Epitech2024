/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_inventory
*/

#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_inventory(client_manager *manager, ai_entry *ai)
{
    send_data(ai->data.ai_socket, "[food %zu,linemate %zu,deraumere %zu,"
    "sibur %zu,mendiane %zu,phiras %zu,thystame %zu]\n",
    ai->data.inventory.food, ai->data.inventory.linemate,
    ai->data.inventory.deraumere, ai->data.inventory.sibur,
    ai->data.inventory.mendiane, ai->data.inventory.phiras,
    ai->data.inventory.thystame);
}
#pragma GCC diagnostic error "-Wunused-parameter"