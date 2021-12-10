#include "cli.h"
#include "tools.h"

void recv_messages(self_t *self, response_data data)
{
    char uuid[UUID_STR_LEN] = {0};
    time_t time = 0;
    char body[BODY_STR_LEN] = {0};
    char *message = NULL;

    if (phase_equals(data.message, "You have no active conversation with this user.", EMPTY)) {
        return;
    }
    if (data.code == KO) {
        client_error_unknown_user(self->all[1]);
        return;
    }
    while ((message = strtok(message == NULL ? data.message : NULL, "\n"))) {
        sscanf(message, "TIME(%ld) UUID(%[^)]) BODY(%[^)])", &time, uuid, body);
        client_private_message_print_messages(uuid, time, body);
    }
}
