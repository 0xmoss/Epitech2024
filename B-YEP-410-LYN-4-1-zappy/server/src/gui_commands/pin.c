/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_pin
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_pin(client_manager *manager, gui_entry *gui)
{
    char *id_str = strtok(NULL, " \n");
    size_t id = id_str ? atol(id_str) : 0;
    ai_entry *ai = find_ai_by_id(manager, id);

    if (id_str == NULL || ai == NULL) {
        send(gui->data.gui_socket, "sbp\n", 4, 0);
    } else {
        send_data(gui->data.gui_socket, "pin %zu %zu %zu %zu %zu %zu %zu %zu %zu %zu\n",
        id, ai->data.pos.x, ai->data.pos.y, ai->data.inventory.food, ai->data.inventory.linemate,
        ai->data.inventory.deraumere, ai->data.inventory.sibur, ai->data.inventory.mendiane,
        ai->data.inventory.phiras, ai->data.inventory.thystame);
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"