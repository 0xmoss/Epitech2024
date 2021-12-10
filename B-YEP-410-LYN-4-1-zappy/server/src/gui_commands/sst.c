/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_sst
*/

#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_sst(client_manager *manager, gui_entry *gui)
{
    char *time_unit_str = strtok(NULL, " \n");
    size_t time_unit = time_unit_str ? atol(time_unit_str) : 0;

    if (time_unit_str == NULL || 2 > time_unit || time_unit > 10000) {
        send(gui->data.gui_socket, "sbp\n", 4, 0);
    } else {
        manager->symdata->time_unit_reciprocal = time_unit;
        send_data(gui->data.gui_socket, "sst %zu\n", manager->symdata->time_unit_reciprocal);
    }
}
#pragma GCC diagnostic error "-Wunused-parameter"