/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_use.c
*/

#include "cli.h"
#include "tools.h"

void recv_use(self_t *self, response_data data)
{
    char uuid[UUID_STR_LEN] = {0};

    if (phase_startswith(data.message, "Team with\0", EMPTY) == True) {
        sscanf(data.message, "Team with UUID(%[^)])", uuid);
    } else if (phase_startswith(data.message, "Thread with\0", EMPTY) == True) {
        sscanf(data.message, "Thread with UUID(%[^)])", uuid);
    } else if (phase_startswith(data.message, "Channel with\0", EMPTY) == True) {
        sscanf(data.message, "Channel with UUID(%[^)])", uuid);
    } else {
        printf("%s\n", data.message);
    }
}