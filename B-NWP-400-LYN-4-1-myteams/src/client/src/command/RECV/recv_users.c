#include "tools.h"
#include "cli.h"
#include "logging_client.h"

void recv_users(self_t *self, response_data data)
{
    char name[NAME_STR_LEN] = {0};
    char uuid[UUID_STR_LEN] = {0};
    int connected = 0;
    char *message = NULL;

    while ((message = strtok(message == NULL ? data.message : NULL, "\n"))) {
        sscanf(message, "UUID(%[^)]) NAME(%[^)]) CONNECTED(%d)", uuid, name, &connected);
        client_print_users(uuid, name, connected);
    }
}
