/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** command
*/

#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include "struct.h"
#include "const.h"

static inline ssize_t find_request_index(
    const char (*names)[16], const char *name)
{
    if (name == NULL)
        return -1;
    for (size_t i = 0; strcmp(names[i], ""); ++i)
        if (!strcmp(names[i], name))
            return i;
    return -1;
}

void execute_gui_request(
    client_manager *manager, gui_entry *gui, char request[REQUEST_SIZE])
{
    char *command = strtok(request, " \n");
    ssize_t index = find_request_index(GUI_COMMANDS_NAME, command);

    if (index == -1) {
        send(gui->data.gui_socket, "suc\n", 4, 0);
    } else {
        (*GUI_COMMANDS[index])(manager, gui);
    }
}

void execute_ai_request(
    client_manager *manager, ai_entry *ai, char request[REQUEST_SIZE])
{
    char *command = strtok(request, " \n");
    ssize_t index = find_request_index(AI_COMMANDS_NAME, command);

    if (index == -1) {
        send(ai->data.ai_socket, "ko\n", 3, 0);
    } else {
        (*AI_COMMANDS[index])(manager, ai);
    }
}