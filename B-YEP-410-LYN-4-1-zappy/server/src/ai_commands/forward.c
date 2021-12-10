/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_forward
*/

#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_forward(client_manager *manager, ai_entry *ai)
{
    pos_t vector;
    struct object_head *head = get_tile(
        manager->symdata, ai->data.pos.x, ai->data.pos.y);
    object_entry *object = find_ai_at(head, ai);

    if (ai->data.orientation == W || ai->data.orientation == E) {
        vector = (pos_t) { ai->data.orientation == W ? -1 : 1, 0 };
    } else
        vector = (pos_t) { 0, ai->data.orientation == N ? -1 : 1 };
    SLIST_REMOVE(head, object, object_entry, entries);
    ai->data.pos = apply_vector((pos_t)
    {manager->symdata->width, manager->symdata->height}, ai->data.pos, vector);
    head = get_tile(manager->symdata, ai->data.pos.x, ai->data.pos.y);
    SLIST_INSERT_HEAD(head, object, entries);
    send_data_to_gui(manager, "ppo %zu %zu %zu %zu\n", ai->data.number, ai->data.pos.x, ai->data.pos.y, ai->data.orientation);
    send(ai->data.ai_socket, "ok\n", 3, 0);
}
#pragma GCC diagnostic error "-Wunused-parameter"