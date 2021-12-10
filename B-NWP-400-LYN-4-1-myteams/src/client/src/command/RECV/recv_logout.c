#include "cli.h"
#include "tools.h"

void recv_logout(self_t *self, response_data data)
{
    char name[NAME_STR_LEN] = {0};
    char uuid[UUID_STR_LEN] = {0};

    if (self->login == CONNECTED) {
        sscanf(data.message, "You are now disconnected as UUID(%[^)]) NAME(%[^)]).", uuid, name);
        client_event_logged_out(uuid, name);
        self->login = DISCONNECTED;
        uuid_clear(self->cli_uuid);
    } else
        client_error_unauthorized();
}

