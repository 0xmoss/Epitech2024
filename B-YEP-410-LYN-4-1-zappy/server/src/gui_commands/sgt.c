/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_sgt
*/

#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_sgt(client_manager *manager, gui_entry *gui)
{
    send_data(gui->data.gui_socket, "sgt %zu\n", manager->symdata->time_unit_reciprocal);
}
#pragma GCC diagnostic error "-Wunused-parameter"