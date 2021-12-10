#include "cli.h"
#include "tools.h"

void recv_unsubscribe(self_t *self, response_data data)
{
    char uuid[UUID_STR_LEN];

    if (data.code == OK) {
        uuid_unparse(self->cli_uuid, uuid);
        client_print_unsubscribed(uuid, self->all[1]);
    } else if (data.code == KO) {
        client_error_unknown_team(self->all[1]);
    }
}
