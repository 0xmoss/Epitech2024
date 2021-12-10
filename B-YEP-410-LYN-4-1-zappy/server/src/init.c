/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** init
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "struct.h"
#include "prototypes.h"

void init_ai(client_manager *manager, ai_entry *ai, ai_ptr_entry *ai_ptr)
{
    object_entry *object = malloc(sizeof(object_entry));
    struct object_head *object_container;

    object->data.data.ai_ptr = ai_ptr;
    object->data.type = PLAYER;
    ai->data.pos.x = randrange(0, manager->symdata->width, false);
    ai->data.pos.y = randrange(0, manager->symdata->height, false);
    object_container = get_tile(manager->symdata,
    ai->data.pos.x, ai->data.pos.y);
    SLIST_INSERT_HEAD(object_container, object, entries);
    ai->data.elevation = 1;
    ai->data.number = generate_number();
    ai->data.request_in_queue = 0;
    ai->data.waiting_for = 0;
    ai->data.will_execute = false;
    ai->data.time_unit_life = 0;
    ai->data.from_egg = false;
    memset(&ai->data.inventory, 0, sizeof(rscount_t));
    ai->data.inventory.food = 10;
    ai->data.orientation = (orientation_t) randrange(N, W, true);
}

void calculate_positions(
    pos_t pos[3], pos_t diff_pos[9], double distances[10])
{
    ssize_t tmp[4] = POS_INITIALIZER(pos);

    diff_pos[0] = (pos_t) { tmp[0], tmp[1] };
    diff_pos[1] = (pos_t) { tmp[0] - pos[2].x, tmp[1] };
    diff_pos[2] = (pos_t) { tmp[0] + pos[2].x, tmp[1] };
    diff_pos[3] = (pos_t) { tmp[0], tmp[1] - pos[2].y };
    diff_pos[4] = (pos_t) { tmp[0], tmp[1] + pos[2].y };
    diff_pos[5] = (pos_t) { tmp[0] - pos[2].x, tmp[1] - pos[2].y };
    diff_pos[6] = (pos_t) { tmp[0] - pos[2].x, tmp[1] + pos[2].y };
    diff_pos[7] = (pos_t) { tmp[0] + pos[2].x, tmp[1] - pos[2].y };
    diff_pos[8] = (pos_t) { tmp[0] + pos[2].x, tmp[1] + pos[2].y };
    distances[0] = sqrt(pow(tmp[2], 2) + pow(tmp[3], 2));
    distances[1] = sqrt(pow(tmp[2] - pos[2].x, 2) + pow(tmp[3], 2));
    distances[2] = sqrt(pow(tmp[2] + pos[2].x, 2) + pow(tmp[3], 2));
    distances[3] = sqrt(pow(tmp[2], 2) + pow(tmp[3] - pos[2].y, 2));
    distances[4] = sqrt(pow(tmp[2], 2) + pow(tmp[3] + pos[2].y, 2));
    distances[5] = sqrt(pow(tmp[2] - pos[2].x, 2) + pow(tmp[3] - pos[2].y, 2));
    distances[6] = sqrt(pow(tmp[2] - pos[2].x, 2) + pow(tmp[3] + pos[2].y, 2));
    distances[7] = sqrt(pow(tmp[2] + pos[2].x, 2) + pow(tmp[3] - pos[2].y, 2));
    distances[8] = sqrt(pow(tmp[2] + pos[2].x, 2) + pow(tmp[3] + pos[2].y, 2));
    distances[9] = distances[0];
}

static void setup_collider2(
    orientation_t orientation, pos_t worldsize, pos_t pos, pos_t collider[8])
{
    if (orientation == S) {
        collider[0] = apply_vector(worldsize, pos, (pos_t) {0, 1});
        collider[1] = apply_vector(worldsize, pos, (pos_t) {1, 1});
        collider[2] = apply_vector(worldsize, pos, (pos_t) {1, 0});
        collider[3] = apply_vector(worldsize, pos, (pos_t) {1, -1});
        collider[4] = apply_vector(worldsize, pos, (pos_t) {0, -1});
        collider[5] = apply_vector(worldsize, pos, (pos_t) {-1, -1});
        collider[6] = apply_vector(worldsize, pos, (pos_t) {-1, 0});
        collider[7] = apply_vector(worldsize, pos, (pos_t) {-1, 1});
    } else if (orientation == W) {
        collider[0] = apply_vector(worldsize, pos, (pos_t) {-1, 0});
        collider[1] = apply_vector(worldsize, pos, (pos_t) {-1, 1});
        collider[2] = apply_vector(worldsize, pos, (pos_t) {0, 1});
        collider[3] = apply_vector(worldsize, pos, (pos_t) {1, 1});
        collider[4] = apply_vector(worldsize, pos, (pos_t) {1, 0});
        collider[5] = apply_vector(worldsize, pos, (pos_t) {1, -1});
        collider[6] = apply_vector(worldsize, pos, (pos_t) {0, -1});
        collider[7] = apply_vector(worldsize, pos, (pos_t) {-1, -1});
    }
}

void setup_collider(
    orientation_t orientation, pos_t worldsize, pos_t pos, pos_t collider[8])
{
    if (orientation == N) {
        collider[0] = apply_vector(worldsize, pos, (pos_t) {0, -1});
        collider[1] = apply_vector(worldsize, pos, (pos_t) {-1, -1});
        collider[2] = apply_vector(worldsize, pos, (pos_t) {-1, 0});
        collider[3] = apply_vector(worldsize, pos, (pos_t) {-1, 1});
        collider[4] = apply_vector(worldsize, pos, (pos_t) {0, 1});
        collider[5] = apply_vector(worldsize, pos, (pos_t) {1, 1});
        collider[6] = apply_vector(worldsize, pos, (pos_t) {1, 0});
        collider[7] = apply_vector(worldsize, pos, (pos_t) {1, -1});
    } else if (orientation == E) {
        collider[0] = apply_vector(worldsize, pos, (pos_t) {1, 0});
        collider[1] = apply_vector(worldsize, pos, (pos_t) {1, -1});
        collider[2] = apply_vector(worldsize, pos, (pos_t) {0, -1});
        collider[3] = apply_vector(worldsize, pos, (pos_t) {-1, -1});
        collider[4] = apply_vector(worldsize, pos, (pos_t) {-1, 0});
        collider[5] = apply_vector(worldsize, pos, (pos_t) {-1, 1});
        collider[6] = apply_vector(worldsize, pos, (pos_t) {0, 1});
        collider[7] = apply_vector(worldsize, pos, (pos_t) {1, 1});
    } else
        setup_collider2(orientation, worldsize, pos, collider);
}
