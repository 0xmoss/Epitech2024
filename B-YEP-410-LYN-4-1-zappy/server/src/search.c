/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** search
*/

#include "struct.h"

ai_entry *find_ai_by_id(client_manager *manager, size_t id)
{
    ai_entry *ai;

    SLIST_FOREACH(ai, &manager->ai_head, entries)
        if (ai->data.number == id)
            return ai;
    return NULL;
}

ai_ptr_entry *find_ai_ptr(team_data *team, ai_entry *ai)
{
    ai_ptr_entry *ai_ptr;

    if (ai == NULL)
        return NULL;
    SLIST_FOREACH(ai_ptr, &team->ai_ptr_head, entries)
        if (ai_ptr->data.ai == ai)
            return ai_ptr;
    return NULL;
}

object_entry *find_object_by_ptr(symdata_t *symdata, ai_ptr_entry *ai_ptr)
{
    object_entry *object;

    if (ai_ptr == NULL)
        return NULL;
    for (size_t i = 0; i < symdata->width * symdata->height; ++i)
    SLIST_FOREACH(object, &symdata->map[i], entries)
        if (object->data.type == PLAYER && object->data.data.ai_ptr == ai_ptr)
            return object;
    return NULL;
}

object_entry *find_object_by_type(struct object_head *head, object_type_t type)
{
    object_entry *object;

    if (type == UNDEFINED || head == NULL)
        return NULL;
    SLIST_FOREACH(object, head, entries)
        if (object->data.type == type)
            return object;
    return NULL;
}

object_entry *find_ai_at(struct object_head *head, ai_entry *ai)
{
    object_entry *object;

    if (ai == NULL || head == NULL)
        return NULL;
    SLIST_FOREACH(object, head, entries)
        if (object->data.type == PLAYER && object->data.data.ai_ptr &&
        object->data.data.ai_ptr->data.ai == ai)
            return object;
    return NULL;
}

struct object_head *get_tile(symdata_t *symdata, size_t x, size_t y)
{
    return &symdata->map[y * symdata->width + x];
}