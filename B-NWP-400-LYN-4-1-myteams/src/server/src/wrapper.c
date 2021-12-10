/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams- [WSL: Ubuntu]
** File description:
** wrapper
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "enum.h"
#include "struct.h"

void getline_wrapper(FILE *stream, char *dest, size_t size, ...)
{
    va_list ap;
    char *lineptr = NULL;
    char *current_dest = dest;
    size_t current_size = size;
    size_t n = 0;
    ssize_t readsize;

    va_start(ap, size);
    while (current_dest != NULL) {
        if ((readsize = getline(&lineptr, &n, stream)) < 0)
            break;
        lineptr[readsize - 1] = '\0';
        strncpy(current_dest, lineptr, current_size);
        current_dest = va_arg(ap, char *);
        if (current_dest != NULL)
            current_size = va_arg(ap, size_t);
    }
    if (lineptr != NULL)
        free(lineptr);
    va_end(ap);
}

response_data create_response(response_code code, char const *format, ...)
{
    response_data response;
    va_list ap;
    va_list ap_copy;

    va_start(ap, format);
    va_copy(ap_copy, ap);
    response.code = code;
    response.size = (size_t) vsnprintf(NULL, 0, format, ap);
    va_end(ap);
    response.message = malloc(sizeof(char) * (response.size + 1));
    vsprintf(response.message, format, ap_copy);
    va_end(ap_copy);
    return response;
}

response_data create_temp_response(response_code code)
{
    response_data response;

    response.code = code;
    response.size = 0;
    response.message = malloc(sizeof(char));
    response.message[0] = '\0';
    return response;
}

void append_data(response_data *response, char const *format, ...)
{
    size_t last_size = response->size;
    va_list ap;
    va_list ap_copy;

    va_start(ap, format);
    va_copy(ap_copy, ap);
    response->size += (size_t) vsnprintf(NULL, 0, format, ap);
    va_end(ap);
    response->message = reallocarray(response->message,
    response->size + 1, sizeof(char));
    vsprintf(response->message + last_size, format, ap_copy);
    va_end(ap_copy);
}

enum use_state get_use_state(struct client_entry *client)
{
    return client->data.team != NULL ? 1 : 0 +
    client->data.channel != NULL ? 1 : 0 +
    client->data.thread != NULL ? 1 : 0;
}