/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** help.h
*/

#include "help.h"

#include "phaseout.h"

#include "build.h"
#include "send.h"

size_t HELP(server_t *server, char **data)
{
    send_to_client(server,
    "214 HELP [<SP> <string>] <CRLF>: Display commands\n");
    send_to_client(server, "    QUIT <CRLF>: Disconnection\n");
    send_to_client(server,
    "    USER <SP> <username> <CRLF>: Specify user for authentication\n");
    send_to_client(server,
    "    PASS <SP> <password> <CRLF>: Specify password for authentication\n");
    send_to_client(server, "    PWD <CRLF>: Print working directory\n");
    send_to_client(server,
    "    CWD <SP> <pathname> <CRLF>: Change working directory\n");
    send_to_client(server, "    PASV <CRLF>\n");
    send_to_client(server, "    PORT <SP> <host-port> <CRLF>\n");
    send_to_client(server, "    NOOP <CRLF>: Do nothing\n");
    send_to_client(server, "214 Help message.\n");

    return (True);
}

size_t help(void)
{
    printf("USAGE: ./myftp port path\n      port  %s\n",
        "is the port number on which the server socket listens");
    printf("      path  %s\n",
        "is the path to the home directory for the Anonymous user");

    return (True);
}
