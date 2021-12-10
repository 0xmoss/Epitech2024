/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_look
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "prototypes.h"
#include "extern.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_look(client_manager *manager, ai_entry *ai)
{
    char *response = NULL;
    char *tmp = NULL;
    bool first[2] = {true, true};
    pos_t vector;
    pos_t cursor;
    struct object_head *head;
    object_entry *object;

    response = super_strcat(response, "[");
    for (ssize_t i = 0; i <= (ssize_t) ai->data.elevation; ++i) {
        for (ssize_t j = 0; j <= 2 * i; ++j) {
            tmp = NULL;
            if (ai->data.orientation == W || ai->data.orientation == E) {
                vector = (pos_t) { ai->data.orientation == W ? -i : i, j - i };
            } else
                vector = (pos_t) { j - i, ai->data.orientation == N ? -i : i };
            cursor = apply_vector((pos_t) {manager->symdata->width, manager->symdata->height}, ai->data.pos, vector);
            head = get_tile(manager->symdata, cursor.x, cursor.y);
            first[1] = true;
            SLIST_FOREACH(object, head, entries) {
                tmp = super_strcat(tmp, first[1] ? "%s" : " %s", OBJECT_NAMES[(int) object->data.type]);
                if (first[1])
                    first[1] = false;
            }
            response = super_strcat(response, first[0] ? "%s" : ",%s", tmp ? tmp : "");
            if (tmp)
                free(tmp);
            if (first[0])
                first[0] = false;
        }
    }
    response = super_strcat(response, "]\n");
    send(ai->data.ai_socket, response, strlen(response), 0);
    free(response);
}
#pragma GCC diagnostic error "-Wunused-parameter"