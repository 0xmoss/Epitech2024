/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** const
*/

#pragma once

#include "prototypes.h"
#include "define.h"

const char HELP_COMMAND[] =
    "/help : show help\n"
    "/login [\"user_name\"] : set the user_name used by client\n"
    "/logout : disconnect the client from the server\n"
    "/users : get the list of all users that exist on the domain\n"
    "/user [\"user_uuid\"] : get information about a user\n"
    "/send [\"user_uuid\"] [\"message_body\"] : send a message to a user\n"
    "/messages [\"user_uuid\"] : list all messages exchange with an user\n"
    "/subscribe [\"team_uuid\"] : subscribe to the event of a team and its"
    " sub directories (enable reception of all events from a team)\n"
    "/subscribed ?[\"team_uuid\"] : list all subscribed teams or list all"
    " users subscribed to a team\n"
    "/unsubscribe [\"team_uuid\"] : unsubscribe from a team\n"
    "/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use "
    "specify a context team/channel/thread\n"
    "/create : based on what is being used create the sub resource"
    " (see below)\n"
    "/list : based on what is being used list all the sub resources"
    " (see below)\n"
    "/info : based on what is being used list the current (see below)"
    "When the context is not defined (/use) :\n"
    "\t/create : [\"team_name\"] [\"team_description\"] : "
    "create a new team\n"
    "\t/list : list all existing teams\n"
    "\t/info : display currently logged user infos\n"
    "When team_uuid is defined (/use \"team_uuid\") :\n"
    "\t/create [\"channel_name\"] [\"channel_description\"] : "
    "create a new channel\n"
    "\t/list : list all existing channels\n"
    "\t/info : display currently selected team infos\n"
    "When team_uuid and channel_uuid are defined (/use \"team_uuid\" "
    "\"channel_uuid\") :\n"
    "\t/create [\"thread_title\"] [\"thread_message\"] "
    ": create a new thread\n"
    "\t/list : list all existing threads\n"
    "\t/info : display currently selected channel infos\n"
    "When team_uuid, channel_uuid and thread_uuid are defined (/use"
    "\"team_uuid\" \"channel_uuid\" \"thread_uuid\") :\n"
    "\t/create [\"comment_body\"] : create a new reply\n"
    "\t/list : list all existing replies\n"
    "\t/info : display currently selected thread infos\n";

const char COMMAND_NAMES[COMMANDS_NUMBER][MAX_COMMAND_LENGTH] = {
    "create",
    "help",
    "info",
    "list",
    "login",
    "logout",
    "messages",
    "send",
    "subscribe",
    "subscribed",
    "unsubscribe",
    "use",
    "user",
    "users"
};

const bool COMMAND_AUTH_REQUIRE[COMMANDS_NUMBER] = {
    true,
    false,
    true,
    true,
    false,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true
};

response_data (*COMMAND_FUNCS[COMMANDS_NUMBER])(
    client_manager *manager,
    struct client_entry *client,
    request_data *data
) = {
    create_command,
    help_command,
    info_command,
    list_command,
    login_command,
    logout_command,
    messages_command,
    send_command,
    subscribe_command,
    subscribed_command,
    unsubscribe_command,
    use_command,
    user_command,
    users_command
};