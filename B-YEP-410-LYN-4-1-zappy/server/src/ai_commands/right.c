/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** ai_right
*/

#include <sys/socket.h>
#include "define.h"
#include "prototypes.h"
#include "struct.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void ai_right(client_manager *manager, ai_entry *ai)
{
    if (ai->data.orientation == N) {
        ai->data.orientation = E;
    } else if (ai->data.orientation == E) {
        ai->data.orientation = S;
    } else if (ai->data.orientation == S) {
        ai->data.orientation = W;
    } else {
        ai->data.orientation = N;
    }
    send_data_to_gui(manager, "ppo %zu %zu %zu %zu\n", ai->data.number, ai->data.pos.x, ai->data.pos.y, ai->data.orientation);
    send(ai->data.ai_socket, "ok\n", 3, 0);
}
#pragma GCC diagnostic error "-Wunused-parameter"