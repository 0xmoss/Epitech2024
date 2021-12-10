/*
** EPITECH PROJECT, 2020
** teams
** File description:
** build.c
*/

#include "tools.h"
#include "cli.h"

self_t *build(void)
{
    self_t *self = malloc(sizeof(self_t));

    self->login = DISCONNECTED;
    self->master = 0;

    uuid_clear(self->cli_uuid);

    self->all = NULL;

    self->command = NULL;
    self->name = NULL;
    self->body = NULL;
    self->description = NULL;

    self->uid0 = NULL;
    self->uid1 = NULL;
    self->uid2 = NULL;

    self->use = 0;

    return (self);
}
