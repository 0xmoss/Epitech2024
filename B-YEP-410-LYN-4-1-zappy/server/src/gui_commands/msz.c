/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** gui_msz
*/

#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void gui_msz(client_manager *manager, gui_entry *gui)
{
    send_data(gui->data.gui_socket, "msz %zu %zu\n", manager->symdata->width, manager->symdata->height);
}
#pragma GCC diagnostic error "-Wunused-parameter"