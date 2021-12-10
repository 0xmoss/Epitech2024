/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_broadcast
*/

#include <string.h>
#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_broadcast(client_manager *manager, ai_entry *ai)
{
    char *message = strtok(NULL, " \n");

    if (message)
        generate_sound(manager, ai, message);
    send(ai->data.ai_socket, "ok\n", 3, 0);
}
#pragma GCC diagnostic error "-Wunused-parameter"