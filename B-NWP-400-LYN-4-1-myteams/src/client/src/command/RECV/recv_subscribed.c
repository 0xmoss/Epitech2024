/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-
** File description:
** recv_subscribed.c
*/

#include "cli.h"
#include "tools.h"

void recv_subscribed(self_t *self, response_data data)
{
    char uuid[UUID_STR_LEN] = {0};
    char name[NAME_STR_LEN] = {0};
    char description[DESCRIPTION_STR_LEN] = {0};
    int connected = 0;
    char *message = NULL;
    size_t team_mode;
    
    if (data.code == KO) {
        client_error_unknown_team(self->all[1]);
        return;
    }
    while ((message = strtok(message == NULL ? data.message : NULL, "\n"))) {
        if (phase_equals(message, "You are currently subscribed in:", EMPTY)) {
            team_mode = True; 
        } else if (phase_equals(message, "The users subscribed to this team are:", EMPTY)) {
            team_mode = False;
        } else if (team_mode == True) {
            sscanf(message, "UUID(%[^)]) NAME(%[^)]) DESCRIPTION(%[^)])", uuid, name, description);
            client_print_teams(uuid, name, description);
        } else if (team_mode == False) {
            sscanf(message, "UUID(%[^)]) NAME(%[^)]) CONNECTED(%d)", uuid, name, &connected);
            client_print_users(uuid, name, connected);
        }
    }
}
