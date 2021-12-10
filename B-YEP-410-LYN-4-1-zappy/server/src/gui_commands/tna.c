/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_tna
*/

#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_tna(client_manager *manager, gui_entry *gui)
{
    for (size_t i = 0; manager->symdata->teams[i].name != NULL; ++i)
        send_data(gui->data.gui_socket, "tna %s\n", manager->symdata->teams[i].name);
}
#pragma GCC diagnostic error "-Wunused-parameter"