/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_eject
*/

#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_eject(client_manager *manager, ai_entry *ai)
{
    struct object_head *head = get_tile(manager->symdata, ai->data.pos.x, ai->data.pos.y);
    struct object_head *nhead;
    size_t player_count = count_player_on_tile(manager->symdata, NULL, ai->data.pos.x, ai->data.pos.y);
    object_entry *object;
    ai_entry *cursor;
    object_entry *next;
    pos_t vector;

    if (ai->data.orientation == W || ai->data.orientation == E) {
        vector = (pos_t) { ai->data.orientation == W ? -1 : 1, 0 };
    } else
        vector = (pos_t) { 0, ai->data.orientation == N ? -1 : 1 };
    if (player_count > 1) {
        next = SLIST_FIRST(head);
        while ((object = next) != NULL) {
            next = SLIST_NEXT(object, entries);
            if (object->data.type != PLAYER || ai == object->data.data.ai_ptr->data.ai)
                continue;
            SLIST_REMOVE(head, object, object_entry, entries);
            cursor = object->data.data.ai_ptr->data.ai;
            cursor->data.pos = apply_vector((pos_t)
            {manager->symdata->width, manager->symdata->height}, cursor->data.pos, vector);
            nhead = get_tile(manager->symdata, cursor->data.pos.x, cursor->data.pos.y);
            SLIST_INSERT_HEAD(nhead, object, entries);
            send_data_to_gui(manager, "pex %zu\n", cursor->data.number);
            send_data_to_gui(manager, "ppo %zu %zu %zu %zu\n", cursor->data.number, cursor->data.pos.x, cursor->data.pos.y, cursor->data.orientation);
            if (ai->data.orientation == N)
                send_data(cursor->data.ai_socket, "eject: %d\n", S);
            else if (ai->data.orientation == S)
                send_data(cursor->data.ai_socket, "eject: %d\n", N);
            else if (ai->data.orientation == W)
                send_data(cursor->data.ai_socket, "eject: %d\n", E);
            else if (ai->data.orientation == E)
                send_data(cursor->data.ai_socket, "eject: %d\n", W);
        }
        send(ai->data.ai_socket, "ok\n", 3, 0);
    } else {
        send(ai->data.ai_socket, "ko\n", 3, 0);
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"