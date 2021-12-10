/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** prototypes
*/

#pragma once

#include <stdlib.h>
#include <stdarg.h>
#include "struct.h"
#include "global_struct.h"
#include "enum.h"

response_data create_response(response_code code, char const *format, ...);
response_data create_temp_response(response_code code);
void append_data(response_data *response, char const *format, ...);
void getline_wrapper(FILE *stream, char *dest, size_t size, ...);
enum use_state get_use_state(struct client_entry *client);

void teams_server(int server_socket);

bool send_data_to_uuid(
    client_manager *manager, response_data data, uuid_t uuid, bool free_mode);
bool send_data_to_name(
    client_manager *manager, response_data data, const char *name, bool);
bool send_data_to_client(
    struct client_entry *client, response_data data, bool free_mode);
int init_server(u_int16_t port);

client_manager load_manager(void);
void dump_manager(client_manager *manager);
void unload_manager(client_manager *manager);

struct conversation_entry *find_conversation_by_name(
    client_manager *manager, char const *name0, char const *name1);
struct team_ptr_entry *find_subscribed_team_by_name(
    struct user_entry *user, char const *name);
struct team_ptr_entry *find_subscribed_team_by_uuid(
    struct user_entry *user, uuid_t uuid);
struct user_ptr_entry *find_subscribed_user_by_name(
    struct team_entry *team, const char *name);
struct user_ptr_entry *find_subscribed_user_by_uuid(
    struct team_entry *team, uuid_t uuid);

struct client_entry *new_client(int server_socket);
void delete_client(struct client_entry *client);
struct user_entry *find_user_by_name(
    client_manager *manager, const char *name);
struct user_entry *find_user_by_uuid(
    client_manager *manager, uuid_t uuid);
struct client_entry *find_client_by_name(
    client_manager *manager, const char *name);
struct client_entry *find_client_by_uuid(client_manager *manager, uuid_t uuid);
struct team_entry *find_team_by_name(
    client_manager *manager, const char *name);
struct team_entry *find_team_by_uuid(client_manager *manager, uuid_t uuid);
struct channel_entry *find_channel_by_name(
    struct team_entry *team, const char *name);
struct channel_entry *find_channel_by_uuid(
    struct team_entry *team, uuid_t uuid);
struct thread_entry *find_thread_by_name(
    struct channel_entry *channel, const char *name);
struct thread_entry *find_thread_by_uuid(
    struct channel_entry *channel, uuid_t uuid);

request_data parse_request(struct client_entry *client, request_data *data);
response_data execute_request(
    client_manager *manager, struct client_entry *client, request_data *data);

response_data create_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data help_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data info_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data list_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data login_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data logout_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data messages_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data send_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data subscribe_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data subscribed_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data unsubscribe_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data use_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data user_command(
    client_manager *manager, struct client_entry *client, request_data *data);
response_data users_command(
    client_manager *manager, struct client_entry *client, request_data *data);