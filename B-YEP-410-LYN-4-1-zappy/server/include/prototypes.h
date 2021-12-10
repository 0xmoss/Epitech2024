/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** prototypes
*/

#pragma once

#include <sys/select.h>
#include <stdarg.h>
#include <sys/types.h>
#include <stdbool.h>
#include "struct.h"

// optparser.c

bool parse_opt(symdata_t *symdata, char **argv, size_t argc, int opt);
bool parse_port(symdata_t *symdata, char *optarg);
bool parse_width(symdata_t *symdata, char *optarg);
bool parse_height(symdata_t *symdata, char *optarg);
bool parse_team_names(symdata_t *symdata, char **argv, size_t argc, int optind);
bool parse_max_client_per_team(symdata_t *symdata, char *optarg);
bool parse_time_unit_reciprocal(symdata_t *symdata, char *optarg);
bool return_error(char const *string);

// server.c

bool server_listener(symdata_t *symdata, int server_socket);

// handler.c

void fd_switch(client_manager *manager, fd_set *rdfs, int server_socket);
void action_switch(client_manager *manager);

// connection.c

ssize_t recv_data(int socket, char *dest, size_t max);
client_entry *new_client(int server_socket);

// adder.c

void add_to_ai_client(
    client_manager *manager, client_entry *client, size_t team_id);
void add_to_gui_client(
    client_manager *manager, client_entry *client);


// utils.c

ssize_t check_team_valid(client_manager *manager, char const *name);
size_t randrange(size_t min, size_t max, bool include_last);
size_t *resource_pointer(ai_entry *ai, object_type_t type);
size_t count_player_on_tile(symdata_t *symdata, ai_entry *ai, size_t x, size_t y);

// data.c

int send_data(int socket, char const *format, ...);
int send_data_to_gui(client_manager *manager, char const *format, ...);
char *super_strcat(char *str0, char const *str1, ...);

// init.c

void setup_collider(
    orientation_t orientation, pos_t worldsize, pos_t pos, pos_t collider[8]);
void calculate_positions(
    pos_t pos[3], pos_t diff_pos[9], double distances[10]);
void init_ai(client_manager *manager, ai_entry *ai, ai_ptr_entry *ai_ptr);

// generator.c

bool generate_resource(client_manager *manager, symdata_t *symdata);
void generate_sound(
    client_manager *manager, ai_entry *ai, const char *message);
size_t generate_number(void);
egg_entry *retrieve_hatched_egg(team_data *team);
bool generate_incantation(symdata_t *symdata, ai_entry *ai, bool start);

// vector.c

pos_t norm_vector(pos_t worldsize, pos_t pos);
pos_t apply_vector(pos_t worldsize, pos_t pos, pos_t vector);

// command.c

void execute_gui_request(
    client_manager *manager, gui_entry *gui, char request[REQUEST_SIZE]);
void execute_ai_request(
    client_manager *manager, ai_entry *ai, char request[REQUEST_SIZE]);

// destroy.c

void destroy_ai(client_manager *manager, ai_entry *ai);

// search.c

ai_ptr_entry *find_ai_ptr(team_data *team, ai_entry *ai);
struct object_head *get_tile(symdata_t *symdata, size_t x, size_t y);
object_entry *find_object_by_ptr(symdata_t *symdata, ai_ptr_entry *ai_ptr);
object_entry *find_ai_at(struct object_head *head, ai_entry *ai);
object_entry *find_object_by_type(struct object_head *head, object_type_t type);
ai_entry *find_ai_by_id(client_manager *manager, size_t id);

// ai_command/

void ai_broadcast(client_manager *manager, ai_entry *ai);
void ai_connectnbr(client_manager *manager, ai_entry *ai);
void ai_eject(client_manager *manager, ai_entry *ai);
void ai_fork(client_manager *manager, ai_entry *ai);
void ai_forward(client_manager *manager, ai_entry *ai);
void ai_incantation(client_manager *manager, ai_entry *ai);
void ai_inventory(client_manager *manager, ai_entry *ai);
void ai_left(client_manager *manager, ai_entry *ai);
void ai_look(client_manager *manager, ai_entry *ai);
void ai_right(client_manager *manager, ai_entry *ai);
void ai_set(client_manager *manager, ai_entry *ai);
void ai_take(client_manager *manager, ai_entry *ai);

// gui_command/

void custom_bct(client_manager *manager, size_t x, size_t y);

void gui_bct(client_manager *manager, gui_entry *gui);
void gui_mct(client_manager *manager, gui_entry *gui);
void gui_msz(client_manager *manager, gui_entry *gui);
void gui_pin(client_manager *manager, gui_entry *gui);
void gui_plv(client_manager *manager, gui_entry *gui);
void gui_ppo(client_manager *manager, gui_entry *gui);
void gui_sgt(client_manager *manager, gui_entry *gui);
void gui_sst(client_manager *manager, gui_entry *gui);
void gui_tna(client_manager *manager, gui_entry *gui);