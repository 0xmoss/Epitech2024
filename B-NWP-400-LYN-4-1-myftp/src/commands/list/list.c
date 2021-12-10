/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "list.h"

#include "phaseout.h"
#include "dirent.h"

#include "build.h"
#include "send.h"

size_t execute_list(server_t *server, char *path)
{
    DIR *d;
    struct dirent *dir;

    d = opendir(path);

    if (d != NULL) {
        while ((dir = readdir(d)) != NULL) {
            send_to_client(server, dir->d_name);
            send_to_client(server, "\n");
        }
        closedir(d);
    } else {
        send_to_client(server, "xxx directory not found\n");
    }

    return (True);
}

size_t LIST(server_t *server, char **data)
{
    char **args = NULL;
    size_t size = phase_llength(data, NULL);

    send_to_client(server, "150\n");

    if (size > 1) {
        if (size == 2) {
            args = phase_mmalloc(data[1], NULL);
            send_to_client(server, "226\n");
            execute_list(server, data[1]);
        } else
            send_to_client(server, "xxx Arguments error\n");
    } else {
        send_to_client(server, "226\n");
        execute_list(server, ".");
    }

    return (True);
}
