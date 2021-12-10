/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "prototypes.h"

void destroy_ai(client_manager *manager, ai_entry *ai)
{
    ai_ptr_entry *ai_ptr;
    object_entry *object;
    struct object_head *tile;

    ai_ptr = find_ai_ptr(&manager->symdata->teams[ai->data.team_id], ai);
    object = find_object_by_ptr(manager->symdata, ai_ptr);
    tile = get_tile(manager->symdata, ai->data.pos.x, ai->data.pos.y);
    SLIST_REMOVE(&manager->symdata->teams[ai->data.team_id].ai_ptr_head,
    ai_ptr, ai_ptr_entry, entries);
    manager->symdata->teams[ai->data.team_id].connected -= 1;
    if (ai->data.from_egg)
        manager->symdata->teams[ai->data.team_id].max_connected -= 1;
    SLIST_REMOVE(tile, object, object_entry, entries);
    SLIST_REMOVE(&manager->ai_head, ai, ai_entry, entries);
    close(ai->data.ai_socket);
    free(ai);
    free(object);
    free(ai_ptr);
}