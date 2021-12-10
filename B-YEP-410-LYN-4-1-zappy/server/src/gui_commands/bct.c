/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_bct
*/

#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

void custom_bct(client_manager *manager, size_t x, size_t y)
{
    struct object_head *head;
    object_entry *object;
    size_t quantities[7] = {0, 0, 0, 0, 0, 0, 0};

    if (!(x >= manager->symdata->width || y >= manager->symdata->height)) {
        head = get_tile(manager->symdata, x, y);
        SLIST_FOREACH(object, head, entries)
            if (object->data.type != PLAYER)
                quantities[(size_t) (object->data.type - 1)] += 1;
        send_data_to_gui(manager, "bct %zu %zu %zu %zu %zu %zu %zu %zu %zu\n",
        x, y, quantities[0], quantities[1], quantities[2], quantities[3], quantities[4], quantities[5], quantities[6]);
    }
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_bct(client_manager *manager, gui_entry *gui)
{
    char *x_str = strtok(NULL, " \n");
    char *y_str = strtok(NULL, " \n");
    size_t x = x_str ? atol(x_str) : 0;
    size_t y = y_str ? atol(y_str) : 0;
    struct object_head *head;
    object_entry *object;
    size_t quantities[7] = {0, 0, 0, 0, 0, 0, 0};

    if (x_str == NULL || y_str == NULL || x >= manager->symdata->width || y >= manager->symdata->height) {
        send(gui->data.gui_socket, "sbp\n", 4, 0);
    } else {
        head = get_tile(manager->symdata, x, y);
        SLIST_FOREACH(object, head, entries)
            if (object->data.type != PLAYER)
                quantities[(size_t) (object->data.type - 1)] += 1;
        send_data(gui->data.gui_socket, "bct %zu %zu %zu %zu %zu %zu %zu %zu %zu\n",
        x, y, quantities[0], quantities[1], quantities[2], quantities[3], quantities[4], quantities[5], quantities[6]);
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"