/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** generator
*/

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <math.h>
#include "prototypes.h"
#include "extern.h"

void generate_sound(
    client_manager *manager, ai_entry *ai, const char *message)
{
    pos_t pos[4] = { ai->data.pos, {0, 0}, {manager->symdata->width, manager->symdata->height}, {0, 0} };
    pos_t collider[8];
    pos_t diff_pos[9];
    double distances[10];
    double error[3] = {0, 0, -1.0};
    ai_entry *cursor;

    send_data_to_gui(manager, "pbc %zu %s\n", ai->data.number, message);
    SLIST_FOREACH(cursor, &manager->ai_head, entries) {
        if (ai == cursor)
            continue;
        pos[1] = cursor->data.pos;
        if (pos[1].x == pos[0].x && pos[1].y == pos[1].y) {
            send_data(cursor->data.ai_socket, "message 0, %s\n", message);
            continue;
        }
        calculate_positions(pos, diff_pos, distances);
        setup_collider(cursor->data.orientation, pos[2], pos[1], collider);
        for (size_t i = 1; i < 9; ++i)
        if (distances[i] < distances[9]) {
            distances[9] = distances[i];
            error[0] = 0.0;
            error[1] = (double) diff_pos[i].y / (double) diff_pos[i].x;
        }
        for (pos[3] = pos[1]; pos[3].x != pos[0].x; pos[3] = apply_vector(pos[2], pos[3], (pos_t) {1, 0})) {
            for (size_t i = 0; i < 8; ++i)
                if (pos[3].x == collider[i].x && pos[3].y == collider[i].y) {
                    send_data(cursor->data.ai_socket, "message %zu, %s\n", i + 1, message);
                    cursor = NULL;
                    break;
                }
            if (cursor == NULL)
                break;
            if ((error[0] += error[1]) >= 0.5) {
                pos[3] = apply_vector(pos[2], pos[3], (pos_t) {0, 1});
                error[0] += error[2];
            }
        }
    }
}

static inline object_type_t generate_type(symdata_t *symdata)
{
    bool candidates[THYSTAME] = {true, true, true, true, true, true, true};
    size_t candidates_len = (size_t) THYSTAME;
    size_t index;

    for (size_t i = 0; i < THYSTAME; i++)
        if (symdata->count[i] == 0)
            return (object_type_t) (i + 1);
        else if (symdata->count[i] >= symdata->limit[i]) {
            candidates[i] = false;
            candidates_len -= 1;
        }
    if (candidates_len == 0)
        return UNDEFINED;
    index = randrange(0, candidates_len, false);
    for (size_t i = 0; i < THYSTAME; i++)
        if (index == 0 && candidates[i] == true) {
            return (object_type_t) (i + 1);
        } else if (candidates[i] == true)
            index -= 1;
    return UNDEFINED;
}

bool generate_resource(client_manager *manager, symdata_t *symdata)
{
    static pos_t last_pos = { 65565, 65565 };
    object_type_t type = generate_type(symdata);
    object_entry *object;
    struct object_head *head;
    pos_t pos;

    if (type == UNDEFINED)
        return false;
    pos = (pos_t) { randrange(0, symdata->width, false),
    randrange(0, symdata->height, false) };
    while (pos.x == last_pos.x && pos.y == last_pos.y)
        pos = (pos_t) { randrange(0, symdata->width, false),
        randrange(0, symdata->height, false) };
    if ((head = get_tile(symdata, pos.x, pos.y)) == NULL ||
        (object = malloc(sizeof(object_entry))) == NULL)
            return false;
    symdata->count[type - 1] += 1;
    object->data.type = type;
    SLIST_INSERT_HEAD(head, object, entries);
    if (manager)
        custom_bct(manager, pos.x, pos.y);
    last_pos = pos;
    return true;
}

bool generate_incantation(symdata_t *symdata, ai_entry *ai, bool start)
{
    if (ai->data.elevation > 7 ||
        count_player_on_tile(symdata, ai, ai->data.pos.x, ai->data.pos.y) < AI_ELEVATION_COSTS[ai->data.elevation - 1][0] ||
        ai->data.inventory.linemate < AI_ELEVATION_COSTS[ai->data.elevation - 1][1] ||
        ai->data.inventory.deraumere < AI_ELEVATION_COSTS[ai->data.elevation - 1][2] ||
        ai->data.inventory.sibur < AI_ELEVATION_COSTS[ai->data.elevation - 1][3] ||
        ai->data.inventory.mendiane < AI_ELEVATION_COSTS[ai->data.elevation - 1][4] ||
        ai->data.inventory.phiras < AI_ELEVATION_COSTS[ai->data.elevation - 1][5] ||
        ai->data.inventory.thystame < AI_ELEVATION_COSTS[ai->data.elevation - 1][6])
            return false;
    if (start == false) {
        ai->data.elevation += 1;
        ai->data.inventory.linemate -= AI_ELEVATION_COSTS[ai->data.elevation - 1][1];
        ai->data.inventory.deraumere -= AI_ELEVATION_COSTS[ai->data.elevation - 1][2];
        ai->data.inventory.sibur -= AI_ELEVATION_COSTS[ai->data.elevation - 1][3];
        ai->data.inventory.mendiane -= AI_ELEVATION_COSTS[ai->data.elevation - 1][4];
        ai->data.inventory.phiras -= AI_ELEVATION_COSTS[ai->data.elevation - 1][5];
        ai->data.inventory.thystame -= AI_ELEVATION_COSTS[ai->data.elevation - 1][6];
    }
    return true;
}

size_t generate_number(void)
{
    static size_t number = 0;

    return number++;
}