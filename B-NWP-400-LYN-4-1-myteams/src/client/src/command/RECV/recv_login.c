#include "client.h"
#include "tools.h"

void recv_login(self_t *self, response_data data)
{
    char name[NAME_STR_LEN] = {0};
    char uuid[UUID_STR_LEN] = {0};

    if (self->login == DISCONNECTED) {
        if (sscanf(data.message, "You are now authenticated as NAME(%[^)]) UUID(%[^)]).", name, uuid)) {
            client_event_logged_in(uuid, name);
            self->login = CONNECTED;
            uuid_parse(uuid, self->cli_uuid);
        }
    }
}
