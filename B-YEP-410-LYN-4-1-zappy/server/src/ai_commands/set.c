/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_set
*/

#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"
#include "extern.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_set(client_manager *manager, ai_entry *ai)
{
    char *type_str = strtok(NULL, " \n");
    object_type_t type = UNDEFINED;
    struct object_head *head = get_tile(manager->symdata, ai->data.pos.x, ai->data.pos.y);
    size_t *ptr;
    object_entry *object;

    if (type_str == NULL) {
        send(ai->data.ai_socket, "ko\n", 3, 0);
        return;
    }
    for (size_t i = 1; i < 8; ++i)
        if (!strcmp(OBJECT_NAMES[i], type_str))
            type = (object_type_t) i;
    if (type == UNDEFINED || *(ptr = resource_pointer(ai, type)) == 0 ||
        (object = malloc(sizeof(object_entry))) == NULL) {
            send(ai->data.ai_socket, "ko\n", 3, 0);
            return;
    }
    object->data.type = type;
    SLIST_INSERT_HEAD(head, object, entries);
    *ptr -= 1;
    send_data_to_gui(manager, "pin %zu %zu %zu %zu %zu %zu %zu %zu %zu %zu\n", ai->data.number, ai->data.pos.x, ai->data.pos.y,
    ai->data.inventory.food, ai->data.inventory.linemate, ai->data.inventory.deraumere, ai->data.inventory.sibur,
    ai->data.inventory.mendiane, ai->data.inventory.phiras, ai->data.inventory.thystame);
    send_data_to_gui(manager, "pdr %zu %zu\n", ai->data.number, ((size_t) type) - 1);
    custom_bct(manager, ai->data.pos.x, ai->data.pos.y);
    send(ai->data.ai_socket, "ok\n", 3, 0);
}
#pragma GCC diagnostic error "-Wunused-parameter"