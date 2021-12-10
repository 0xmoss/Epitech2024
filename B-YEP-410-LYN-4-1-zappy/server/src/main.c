/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** main
*/

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <getopt.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "prototypes.h"

static inline int print_usage(char const *exec_path)
{
    fprintf(stderr, "\nUSAGE:\t%s -p port -x width -y height "
        "-n name1 name2 ... -c clientsNb -f freq\n\n"
        "\tport\t\tis the port number\n"
        "\twidth\t\tis the width of the world\n"
        "\theight\t\tis the height of the world\n"
        "\tnameX\t\tis the name of the team X\n"
        "\tclientsNb\tis the number of authorized clients per team\n"
        "\tfreq\t\tis the reciprocal of time unit for execution of actions\n",
        exec_path);
    return 84;
}

static int free_symdata(
    char const *exec_path, symdata_t *symdata, int server_socket, bool usage)
{
    ai_ptr_entry *ai_ptr;
    object_entry *object;
    egg_entry *egg;

    if (usage)
        print_usage(exec_path);
    if (symdata->teams) {
        for (size_t i = 0; symdata->teams[i].name != NULL; ++i) {
            SLIST_DESTROY(ai_ptr, &symdata->teams[i].ai_ptr_head, entries);
            SLIST_DESTROY(egg, &symdata->teams[i].egg_head, entries);
        }
        free(symdata->teams);
    }
    if (symdata->map) {
        for (size_t i = 0; i < symdata->width * symdata->height; ++i)
            SLIST_DESTROY(object, &symdata->map[i], entries);
        free(symdata->map);
    }
    if (server_socket != -1)
        close(server_socket);
    return 84;
}

static inline int init_server(uint16_t port)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    const int on = 1;
    struct sockaddr_in addr = SOCKADDR_INITIALIZER(port);

    if (socket_fd < 0)
        return -1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int)) < 0
    #if defined(SO_REUSEPORT)
    || setsockopt(socket_fd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(int)) < 0
    #endif
    || bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        close(socket_fd);
        return -1;
    }
    if (listen(socket_fd, SOMAXCONN) < 0) {
        close(socket_fd);
        return -1;
    }
    return socket_fd;
}

static inline bool init_symdata(symdata_t *symdata)
{
    const size_t total_tile = symdata->width * symdata->height;
    const double densities[THYSTAME] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};

    if (symdata->teams == NULL) {
        symdata->teams = malloc(sizeof(team_data) * 5);
        for (size_t i = 0; i < 4; ++i) {
            SLIST_INIT(&symdata->teams[i].ai_ptr_head);
            SLIST_INIT(&symdata->teams[i].egg_head);
            symdata->teams[i].connected = 0;
            if (i == 0)
                symdata->teams[i].name = "Team1";
            else if (i == 1)
                symdata->teams[i].name = "Team2";
            else if (i == 2)
                symdata->teams[i].name = "Team3";
            else if (i == 3)
                symdata->teams[i].name = "Team4";
        }
        symdata->teams[4].name = NULL;
    }
    symdata->map = malloc(sizeof(struct object_head) * total_tile);
    if (symdata->map == NULL)
        return return_error("ERROR: Not enough memory");
    for (size_t i = 0; symdata->teams[i].name; ++i)
        symdata->teams[i].max_connected = symdata->max_client_per_team;
    for (size_t i = 0; i < total_tile; ++i)
        SLIST_INIT(&symdata->map[i]);
    for (size_t i = 0; i < THYSTAME; ++i)
        symdata->limit[i] = (size_t) (densities[i] * total_tile);
    while (generate_resource(NULL, symdata));
    return true;
}

int main(int argc, char **argv)
{
    int opt;
    int server_socket = -1;
    symdata_t symdata = SYMDATA_INITIALIZER;

    srand(time(NULL));
    while ((opt = getopt(argc, argv, "+p:x:y:n:c:f:")) != -1)
        if (parse_opt(&symdata, argv, (size_t) argc, opt) == false)
            return free_symdata(argv[0], &symdata, server_socket, true);
    if ((server_socket = init_server(symdata.port)) == -1 ||
        init_symdata(&symdata) == false)
            return free_symdata(argv[0], &symdata,
            server_socket, optind >= argc);
    printf("Port : %"PRIu16"\n", symdata.port);
    server_listener(&symdata, server_socket);
    free_symdata(argv[0], &symdata, server_socket, false);
    return 0;
}