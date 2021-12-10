#include "cli.h"
#include "tools.h"

void recv_send(self_t *self, response_data data)
{
    if (data.code == KO) {
        client_error_unknown_user(self->all[1]);
    }
}
