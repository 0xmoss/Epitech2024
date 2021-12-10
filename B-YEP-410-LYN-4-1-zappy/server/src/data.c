/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** data
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int send_data(int socket, char const *format, ...)
{
    int size;
    int ret;
    char *new_msg;
    va_list ap;
    va_list ap_copy;

    va_start(ap, format);
    va_copy(ap_copy, ap);
    size = vsnprintf(NULL, 0, format, ap);
    va_end(ap);
    new_msg = malloc(sizeof(char) * (size + 1));
    ret = vsprintf(new_msg, format, ap_copy);
    send(socket, new_msg, size, 0);
    free(new_msg);
    va_end(ap_copy);
    return ret;
}

int send_data_to_gui(client_manager *manager, char const *format, ...)
{
    int size;
    int ret;
    char *new_msg;
    gui_entry *gui;
    va_list ap;
    va_list ap_copy;

    va_start(ap, format);
    va_copy(ap_copy, ap);
    size = vsnprintf(NULL, 0, format, ap);
    va_end(ap);
    new_msg = malloc(sizeof(char) * (size + 1));
    ret = vsprintf(new_msg, format, ap_copy);
    SLIST_FOREACH(gui, &manager->gui_head, entries)
        send(gui->data.gui_socket, new_msg, size, 0);
    free(new_msg);
    va_end(ap_copy);
    return ret;
}

char *super_strcat(char *str0, char const *str1, ...)
{
    int size;
    char *new_str;
    va_list ap;
    va_list ap_copy;

    va_start(ap, str1);
    va_copy(ap_copy, ap);
    size = vsnprintf(NULL, 0, str1, ap);
    va_end(ap);
    new_str = malloc(sizeof(char) * (size + 1 + (str0 ? strlen(str0) : 0)));
    if (str0)
        strcpy(new_str, str0);
    vsprintf(new_str + (str0 ? strlen(str0) : 0), str1, ap_copy);
    if (str0)
        free(str0);
    va_end(ap_copy);
    return new_str;
}