/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** handler
*/

#include <stdbool.h>
#include <stddef.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"
#include "extern.h"

static void fd_handle_ai(client_manager *manager, ai_entry *ai)
{
    ssize_t size;
    char request[REQUEST_SIZE] = {0};

    size = recv_data(ai->data.ai_socket, request, REQUEST_SIZE);
    if (size > 0) {
        if (ai->data.request_in_queue == MAX_REQUEST)
            return;
        strcpy(ai->data.requests[ai->data.request_in_queue++], request);
    } else if (size < 0) {
        destroy_ai(manager, ai);
    }
}

static void fd_handle_gui(client_manager *manager, gui_entry *gui)
{
    ssize_t size;
    char request[REQUEST_SIZE] = {0};

    size = recv_data(gui->data.gui_socket, request, REQUEST_SIZE);
    if (size > 0) {
        execute_gui_request(manager, gui, request);
    } else if (size < 0) {
        SLIST_REMOVE(&manager->gui_head, gui, gui_entry, entries);
        close(gui->data.gui_socket);
        free(gui);
    }
}

static void fd_handle_client(client_manager *manager, client_entry *client)
{
    ssize_t size;
    char request[REQUEST_SIZE] = {0};

    size = recv_data(client->data.client_socket, request, REQUEST_SIZE);
    if (size > 0) {
        if (!strcmp(request, "GRAPHIC")) {
            add_to_gui_client(manager, client);
        } else if ((size = check_team_valid(manager, request)) >= 0) {
            add_to_ai_client(manager, client, size);
        } else {
            send(client->data.client_socket, "ko\n", 3, 0);
        }
    } else if (size < 0) {
        SLIST_REMOVE(&manager->client_head, client, client_entry, entries);
        close(client->data.client_socket);
        free(client);
    }
}

void fd_switch(client_manager *manager, fd_set *rdfs, int server_socket)
{
    conns_t cur[2] = { CURSOR_INITIALIZER(manager), {} };

    if (FD_ISSET(server_socket, rdfs)) {
        if ((cur[1].client = new_client(server_socket)) != NULL)
            SLIST_INSERT_HEAD(&manager->client_head, cur[1].client, entries);
    } else {
        while ((cur[1].client = cur[0].client) != NULL) {
            cur[0].client = SLIST_NEXT(cur[1].client, entries);
            if (FD_ISSET(cur[1].client->data.client_socket, rdfs))
            fd_handle_client(manager, cur[1].client);
        }
        while ((cur[1].gui = cur[0].gui) != NULL) {
            cur[0].gui = SLIST_NEXT(cur[1].gui, entries);
            if (FD_ISSET(cur[1].gui->data.gui_socket, rdfs))
            fd_handle_gui(manager, cur[1].gui);
        }
        while ((cur[1].ai = cur[0].ai) != NULL) {
            cur[0].ai = SLIST_NEXT(cur[1].ai, entries);
            if (FD_ISSET(cur[1].ai->data.ai_socket, rdfs))
            fd_handle_ai(manager, cur[1].ai);
        }
    }
}

void action_switch(client_manager *manager)
{
    egg_entry *egg;
    ai_entry *ai;
    struct object_head *head;
    object_entry *object;
    ai_entry *tmp = SLIST_FIRST(&manager->ai_head);
    char request[REQUEST_SIZE] = {0};
    char *command;

    if (manager->symdata->time_unit_passed % 20 == 0)
        generate_resource(manager, manager->symdata);
    for (size_t i = 0; manager->symdata->teams[i].name; ++i)
        SLIST_FOREACH(egg, &manager->symdata->teams[i].egg_head, entries)
            if (egg->data.hatching_in > 0) {
                egg->data.hatching_in -= 1;
                if (egg->data.hatching_in == 0)
                    send_data_to_gui(manager, "eht %zu\n", egg->data.number);
            }
    manager->symdata->time_unit_passed += 1;
    while ((ai = tmp) != NULL) {
        tmp = SLIST_NEXT(ai, entries);
        if (ai->data.time_unit_life > 0)
            ai->data.time_unit_life -= 1;
        if (ai->data.time_unit_life == 0) {
            if (ai->data.inventory.food > 0) {
                ai->data.inventory.food -= 1;
                ai->data.time_unit_life += 126;
            } else {
                send_data_to_gui(manager, "pdi %zu\n", ai->data.number);
                send(ai->data.ai_socket, "dead\n", 5, 0);
                destroy_ai(manager, ai);
            }
        } else if (ai->data.will_execute == true) {
            if (ai->data.waiting_for > 1) {
                ai->data.waiting_for -= 1;
            } else {
                execute_ai_request(manager, ai, ai->data.requests[0]);
                for (size_t i = 1; i < ai->data.request_in_queue; ++i)
                    strcpy(ai->data.requests[i - 1], ai->data.requests[i]);
                ai->data.request_in_queue -= 1;
                ai->data.will_execute = false;
                ai->data.waiting_for = 0;
            }
        } else if (ai->data.request_in_queue > 0) {
            strcpy(request, ai->data.requests[0]);
            command = strtok(request, " \n");
            if (!strcmp(command, "Incantation")) {
                if (generate_incantation(manager->symdata, ai, true)) {
                    send(ai->data.ai_socket, "Elevation underway\n", 19, 0);
                    send_data_to_gui(manager, "pic %zu %zu %zu %zu", ai->data.pos.x, ai->data.pos.y, ai->data.elevation, ai->data.number);
                    head = get_tile(manager->symdata, ai->data.pos.x, ai->data.pos.y);
                    SLIST_FOREACH(object, head, entries)
                        if (object->data.type == PLAYER && object->data.data.ai_ptr->data.ai->data.elevation == ai->data.elevation)
                            send_data_to_gui(manager, " %zu", object->data.data.ai_ptr->data.ai->data.number);
                    send_data_to_gui(manager, "\n");
                } else {
                    send(ai->data.ai_socket, "ko\n", 3, 0);
                    for (size_t i = 1; i < ai->data.request_in_queue; ++i)
                        strcpy(ai->data.requests[i - 1], ai->data.requests[i]);
                    ai->data.request_in_queue -= 1;
                    continue;
                }
            }
            ai->data.waiting_for = 0;
            for (size_t i = 0; i < 11; ++i)
                if (!strcmp(command, AI_COMMANDS_NAME[i]))
                    ai->data.waiting_for = AI_COMMANDS_TIME[i];
            ai->data.will_execute = true;
        }
    }
}