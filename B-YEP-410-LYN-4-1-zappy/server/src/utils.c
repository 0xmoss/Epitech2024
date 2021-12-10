/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** utils
*/

#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <time.h>
#include <stddef.h>
#include <stdio.h>
#include "struct.h"
#include "prototypes.h"

egg_entry *retrieve_hatched_egg(team_data *team)
{
    egg_entry *cursor = NULL;

    SLIST_FOREACH(cursor, &team->egg_head, entries)
        if (cursor->data.hatching_in == 0)
            return cursor;
    return NULL;
}

ssize_t check_team_valid(client_manager *manager, char const *name)
{
    if (manager->symdata->teams == NULL)
        return false;
    for (size_t i = 0; manager->symdata->teams[i].name != NULL; i++) {
        if (((manager->symdata->teams[i].connected <
        manager->symdata->max_client_per_team) || 
        retrieve_hatched_egg(&manager->symdata->teams[i])) && 
        !strcmp(manager->symdata->teams[i].name, name))
            return i;
    }
    return -1;
}

size_t randrange(size_t min, size_t max, bool include_last)
{
    size_t range = max - min + (include_last ? 1 : 0);
    double random = ((double) rand() / (double) RAND_MAX);
    size_t nbr = min + (size_t) (random * range);

    while (nbr == max + (include_last ? 1 : 0)) {
        random = ((double) rand() / (double) RAND_MAX);
        nbr = min + (size_t) (random * range);
    }
    return nbr;
}

size_t *resource_pointer(ai_entry *ai, object_type_t type)
{
    size_t *ptr = NULL;

    switch (type) {
        case FOOD:
            ptr = &ai->data.inventory.food;
            break;
        case LINEMATE:
            ptr = &ai->data.inventory.linemate;
            break;
        case DERAUMERE:
            ptr = &ai->data.inventory.deraumere;
            break;
        case SIBUR:
            ptr = &ai->data.inventory.sibur;
            break;
        case MENDIANE:
            ptr = &ai->data.inventory.mendiane;
            break;
        case PHIRAS:
            ptr = &ai->data.inventory.phiras;
            break;
        case THYSTAME:
            ptr = &ai->data.inventory.thystame;
            break;
        default:
            break;
    }
    return ptr;
}

size_t count_player_on_tile(symdata_t *symdata, ai_entry *ai, size_t x, size_t y)
{
    struct object_head *tile = get_tile(symdata, x, y);
    object_entry *object;
    size_t count = 0;

    if (tile == NULL)
        return 0;
    SLIST_FOREACH(object, tile, entries)
        if (object->data.type == PLAYER &&
        (ai == NULL || object->data.data.ai_ptr->data.ai->data.elevation == ai->data.elevation))
            count++;
    return count;
}