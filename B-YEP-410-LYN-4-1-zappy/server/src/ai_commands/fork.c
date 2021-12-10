/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_fork
*/

#include <sys/socket.h>
#include <stdlib.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_fork(client_manager *manager, ai_entry *ai)
{
    egg_entry *egg = malloc(sizeof(egg_entry));

    egg->data.pos = ai->data.pos;
    egg->data.number = generate_number();
    egg->data.orientation = randrange(N, W, true);
    egg->data.hatching_in = 600;
    send_data_to_gui(manager, "enw %zu %zu %zu %zu\n", egg->data.number, ai->data.number, ai->data.pos.x, ai->data.pos.y);
    send_data_to_gui(manager, "pfk %zu\n", ai->data.number);
    manager->symdata->teams[ai->data.team_id].max_connected += 1;
    SLIST_INSERT_HEAD(&manager->symdata->teams[ai->data.team_id].egg_head, egg, entries);
    send(ai->data.ai_socket, "ok\n", 3, 0);
}
#pragma GCC diagnostic error "-Wunused-parameter"