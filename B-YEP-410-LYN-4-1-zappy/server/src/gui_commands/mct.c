/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_mct
*/

#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_mct(client_manager *manager, gui_entry *gui)
{
    struct object_head *head;
    object_entry *object;
    size_t quantities[7];;

    for (size_t y = 0; y < manager->symdata->height; ++y) {
        for (size_t x = 0; x < manager->symdata->width; ++x) {
            head = get_tile(manager->symdata, x, y);
            memset(quantities, 0, sizeof(size_t) * 7);
            SLIST_FOREACH(object, head, entries)
                if (object->data.type != PLAYER)
                    quantities[(size_t) (object->data.type - 1)] += 1;
            send_data(gui->data.gui_socket, "bct %zu %zu %zu %zu %zu %zu %zu %zu %zu\n",
            x, y, quantities[0], quantities[1], quantities[2], quantities[3], quantities[4], quantities[5], quantities[6]);
        }
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"