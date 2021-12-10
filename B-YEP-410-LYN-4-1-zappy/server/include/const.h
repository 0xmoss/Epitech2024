/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** const
*/

#pragma once

#include <stdbool.h>
#include "struct.h"
#include "prototypes.h"

const char OBJECT_NAMES[8][16] = {
    "player",
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

const char AI_COMMANDS_NAME[13][16] = {
    "Forward",
    "Right",
    "Left",
    "Look",
    "Inventory",
    "Broadcast",
    "Connect_nbr",
    "Fork",
    "Eject",
    "Take",
    "Set",
    "Incantation",
    ""
};

const size_t AI_ELEVATION_COSTS[7][7] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
};

const size_t AI_COMMANDS_TIME[12] = {
    7, // "Forward"
    7, // "Right"
    7, // "Left"
    7, // "Look"
    1, // "Inventory"
    7, // "Broadcast"
    0, // "Connect_nbr"
    42, // "Fork"
    7, // "Eject"
    7, // "Take"
    7, // "Set"
    300 // "Incantation"
};

void (* const AI_COMMANDS[12])(client_manager *manager, ai_entry *ai) = {
    &ai_forward,
    &ai_right,
    &ai_left,
    &ai_look,
    &ai_inventory,
    &ai_broadcast,
    &ai_connectnbr,
    &ai_fork,
    &ai_eject,
    &ai_take,
    &ai_set,
    &ai_incantation
};

const char GUI_COMMANDS_NAME[10][16] = {
    "msz",
    "bct",
    "mct",
    "tna",
    "ppo",
    "plv",
    "pin",
    "sgt",
    "sst",
    ""
};

void (* const GUI_COMMANDS[9])(client_manager *manager, gui_entry *gui) = {
    &gui_msz,
    &gui_bct,
    &gui_mct,
    &gui_tna,
    &gui_ppo,
    &gui_plv,
    &gui_pin,
    &gui_sgt,
    &gui_sst
};