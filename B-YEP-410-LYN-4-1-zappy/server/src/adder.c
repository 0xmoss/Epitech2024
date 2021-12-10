/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** adder
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

void add_to_ai_client(
    client_manager *manager, client_entry *client, size_t team_id)
{
    ai_entry *ai = malloc(sizeof(ai_entry));
    ai_ptr_entry *ai_ptr = malloc(sizeof(ai_ptr_entry));
    bool egg_boy = manager->symdata->teams[team_id].connected >= manager->symdata->max_client_per_team;
    egg_entry *egg;

    SLIST_REMOVE(&manager->client_head, client, client_entry, entries);
    manager->symdata->teams[team_id].connected += 1;
    ai_ptr->data.ai = ai;
    ai->data.ai_socket = client->data.client_socket;
    ai->data.team_id = team_id;
    init_ai(manager, ai, ai_ptr);
    if (egg_boy) {
        egg = retrieve_hatched_egg(&manager->symdata->teams[team_id]);
        SLIST_REMOVE(&manager->symdata->teams[team_id].egg_head, egg, egg_entry, entries);
        ai->data.pos = egg->data.pos;
        ai->data.orientation = egg->data.orientation;
        ai->data.from_egg = true;
        send_data_to_gui(manager, "ebo %zu\n", egg->data.number);
        free(egg);
    }
    send_data_to_gui(manager, "pnw %zu %zu %zu %zu %zu %s\n",
    ai->data.number, ai->data.pos.x, ai->data.pos.y, ai->data.orientation,
    ai->data.elevation, manager->symdata->teams[ai->data.team_id].name);
    send_data(ai->data.ai_socket, "%zu\n", manager->symdata->teams[team_id].max_connected - manager->symdata->teams[team_id].connected);
    send_data(ai->data.ai_socket, "%zu %zu\n", manager->symdata->width, manager->symdata->height);
    SLIST_INSERT_HEAD(&manager->ai_head, ai, entries);
    SLIST_INSERT_HEAD(&manager->symdata->teams[team_id].ai_ptr_head, ai_ptr, entries);
    free(client);
}

void add_to_gui_client(client_manager *manager, client_entry *client)
{
    gui_entry *gui;
    ai_entry *ai;
    egg_entry *egg;

    SLIST_REMOVE(&manager->client_head, client, client_entry, entries);
    gui = malloc(sizeof(gui_entry));
    gui->data.gui_socket = client->data.client_socket;
    gui_msz(manager, gui);
    gui_sgt(manager, gui);
    gui_mct(manager, gui);
    gui_tna(manager, gui);
    SLIST_FOREACH(ai, &manager->ai_head, entries)
        send_data_to_gui(manager, "pnw %zu %zu %zu %zu %zu %s\n",
        ai->data.number, ai->data.pos.x, ai->data.pos.y, ai->data.orientation,
        ai->data.elevation, manager->symdata->teams[ai->data.team_id].name);
    if (manager->symdata->teams)
    for (size_t i = 0; manager->symdata->teams[i].name != NULL; ++i) {
        SLIST_FOREACH(egg, &manager->symdata->teams[i].egg_head, entries)
            send_data_to_gui(manager, "enw %zu %zu %zu %zu\n", egg->data.number, ai->data.number, ai->data.pos.x, ai->data.pos.y);
    }
    SLIST_INSERT_HEAD(&manager->gui_head, gui, entries);
    free(client);
}