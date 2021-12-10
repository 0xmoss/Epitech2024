/*
** EPITECH PROJECT, 2020
** teams
** File description:
** send_client.c
*/

#include "phaseout.h"
#include "tools.h"
#include "cli.h"

#include "global_struct.h"

request_data *update_data(
    char *command,
    char *name,
    char *description,
    char *uid0,
    char *uid1,
    char *uid2,
    char *body
)
{
    request_data *data = calloc(sizeof(request_data), 1);

    data->info = (
        (uid0 ? UUID0 : NONE) |
        (uid1 ? UUID1 : NONE) |
        (uid2 ? UUID2 : NONE) |
        (body ? BODY : NONE) |
        (description ? DESCRIPTION : NONE) |
        (name ? NAME : NONE)
    );
    strcpy(data->uuid0, uid0 ? uid0 : "");
    strcpy(data->uuid1, uid1 ? uid1 : "");
    strcpy(data->uuid2, uid2 ? uid2 : "");
    strcpy(data->command, command ? command : "");
    strcpy(data->name, name ? name : "");
    strcpy(data->description, description ? description : "");
    strcpy(data->body, body ? body : "");

    return (data);
}

static void resume(request_data *data)
{
    printf("\n-----------------------------------\n");
    printf("data->info: '%d'\n", data->info);
    printf("data->command: '%s'\n", data->command);
    printf("data->name: '%s'\n", data->name);
    printf("data->body: '%s'\n", data->body);
    printf("data->description: '%s'\n", data->description);
    printf("data->uuid0: '%s'\n", data->uuid0);
    printf("data->uuid1: '%s'\n", data->uuid1);
    printf("data->uuid2: '%s'\n", data->uuid2);
    printf("-----------------------------------\n\n");
}

static void send_all(self_t *self, request_data *data)
{
    unsigned char info = data->info;

    send(self->master, &info, 1, 0);
    send(self->master, data->command, MAX_COMMAND_LENGTH, 0);

    if (data->info & UUID0)
        send(self->master, data->uuid0, MAX_UUID_LENGTH, 0);
    if (data->info & UUID1)
        send(self->master, data->uuid1, MAX_UUID_LENGTH, 0);
    if (data->info & UUID2)
        send(self->master, data->uuid2, MAX_UUID_LENGTH, 0);

    if (data->info & NAME)
        send(self->master, data->name, MAX_NAME_LENGTH, 0);
    if (data->info & DESCRIPTION)
        send(self->master, data->description, MAX_DESCRIPTION_LENGTH, 0);
    if (data->info & BODY)
        send(self->master, data->body, MAX_BODY_LENGTH, 0);
}

static size_t valid(char **data)
{
    for (size_t i = 0; i < phase_llength(data, NULL); i++) {
        if (phase_contains(data[i], '\n', EMPTY) == True)
            return (True);
    }

    return (False);
}

void send_client(self_t *self, char *message)
{
    int len = 0;
    self->all = phase_split(message, ' ', EMPTY, NULL);
    request_data *data = update_data(self->command, NONE, NONE, NONE, NONE, NONE, NONE);

    self->all[0] = phase_split(self->all[0], '/', EMPTY, NULL)[1];
    if (valid(self->all) == False)
        return;
    self->all[phase_llength(self->all, NULL) - 1] = phase_split(self->all[phase_llength(self->all, NULL) - 1], '\n', EMPTY, NULL)[0];
    self->command = self->all[0];
    if (phase_equals(self->command, "\0", EMPTY) != True) {
        if (phase_equals(self->command, "login\0", EMPTY) == True) {
            if (phase_llength(self->all, NULL) == 2)
                self->name = self->all[1];
            else
                self->command = phase_set("help\0", EMPTY);
        }
        data = handler(self, data);
        send_all(self, data);
        parse(self->master, self);
    }
}

