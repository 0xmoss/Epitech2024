/*
** EPITECH PROJECT, 2020
** teams
** File description:
** cli.h
*/

#ifndef CLI_H
    #define CLI_H

    #include "client.h"
    #include "self.h"
    #include "logging_client.h"
    #include "global_struct.h"

    typedef struct commands_s
    {
        request_data *(*command)(self_t *, request_data *);
    } commands_t;

    typedef struct recv_commands_s
    {
        void (*command)(self_t *, response_data);
    } recv_commands_t;

    ////////////////////////////////////////////////////////
    // CLI
    ///////////////////////////////////////////////////////

    // HANDLER
    request_data *handler(self_t *, request_data *);

    // UPDATE ALL DATA
    request_data *update_data(char *, char *, char *, char *, char *, char *, char *);

    // LOGIN
    request_data *cli_login(self_t *, request_data *);
    request_data *cli_logout(self_t *, request_data *);

    // CREATE TEAM
    request_data *cli_create(self_t *, request_data *);

    // HELP
    request_data *cli_help(self_t *, request_data *);

    // SUBSCRIBE
    request_data *cli_subscribe(self_t *, request_data *);
    request_data *cli_subscribed(self_t *, request_data *);
    request_data *cli_unsubscribed(self_t *, request_data *);

    // USERS
    request_data *cli_user(self_t *, request_data *);
    request_data *cli_users(self_t *, request_data *);

    // USE
    request_data *cli_use(self_t *, request_data *);

    // MESSAGES
    request_data *cli_messages(self_t *, request_data *);
    request_data *cli_send(self_t *, request_data *);

    // LIST
    request_data *cli_list(self_t *, request_data *);

    // INFO
    request_data *cli_info(self_t *, request_data *);

    ///////////////////////////////////////////////////////
    // RECV
    ///////////////////////////////////////////////////////

    void recv_handler(self_t *, response_data);

    void recv_help(self_t *, response_data);
    void recv_login(self_t *, response_data);
    void recv_logout(self_t *, response_data);

    void recv_user(self_t *, response_data);
    void recv_users(self_t *, response_data);

    void recv_send(self_t *, response_data);
    void recv_messages(self_t *, response_data);

    void recv_subscribe(self_t *, response_data);
    void recv_subscribed(self_t *, response_data);
    void recv_unsubscribe(self_t *, response_data);

    void recv_create(self_t *, response_data);
    void recv_use(self_t *, response_data);
    void recv_list(self_t *, response_data);
    void recv_info(self_t *, response_data);

#endif /* CLI_H */

