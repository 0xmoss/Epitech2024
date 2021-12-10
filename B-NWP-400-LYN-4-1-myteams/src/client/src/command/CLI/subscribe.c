/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "tools.h"
#include "cli.h"
#include "phaseout.h"

request_data *cli_subscribed(self_t *self, request_data *data)
{
    size_t size = phase_llength(self->all, NULL);

    if (size == 2 || size == 1) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            size == 2 ? self->all[1] : NULL,
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}

request_data *cli_subscribe(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 2) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            self->all[1],
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}

request_data *cli_unsubscribed(self_t *self, request_data *data)
{
    if (phase_llength(self->all, NULL) == 2) {
        return (update_data(
            self->all[0],
            NULL,
            NULL,
            self->all[1],
            NULL,
            NULL,
            NULL
        ));
    }

    return (data);
}
