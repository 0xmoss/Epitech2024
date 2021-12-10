/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** optparser
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "prototypes.h"
#include "define.h"

bool parse_port(symdata_t *symdata, char *optarg)
{
    char *endptr = NULL;
    long long port = strtoll(optarg, &endptr, 10);

    if (endptr == NULL || *endptr != '\0' || 0 > port || port > 65535)
        return return_error(PORT_ERROR_STR);
    symdata->port = port;
    return true;
}

bool parse_width(symdata_t *symdata, char *optarg)
{
    char *endptr = NULL;
    long long width = strtoll(optarg, &endptr, 10);

    if (endptr == NULL || *endptr != '\0' || 10 > width || width > 30)
        return return_error(WIDTH_ERROR_STR);
    symdata->width = width;
    return true;
}

bool parse_height(symdata_t *symdata, char *optarg)
{
    char *endptr = NULL;
    long long height = strtoll(optarg, &endptr, 10);

    if (endptr == NULL || *endptr != '\0' || 10 > height || height > 30)
        return return_error(HEIGHT_ERROR_STR);
    symdata->height = height;
    return true;
}

static inline bool check_opt(char *arg)
{
    return (arg != NULL && *arg == '-' && strlen(arg) == 2);
}

bool parse_team_names(symdata_t *symdata, char **argv, size_t argc, int optind)
{
    size_t idx = 0;
    size_t size = 0;

    for (size_t i = optind - 1; i < argc && !check_opt(argv[i]); ++i) {
        if (!strcmp(argv[i], "GRAPHIC"))
            return return_error(NAME_ERROR_STR);
        for (size_t j = optind - 1; j < argc && !check_opt(argv[j]); ++j)
        if ((i != j && !strcmp(argv[i], argv[j])))
            return return_error(NAME_ERROR_STR);
        size += 1;
    }
    symdata->teams = malloc((size + 1) * sizeof(team_data));
    if (symdata->teams == NULL)
        return return_error("ERROR: Not enough memory");
    symdata->teams[size].name = NULL;
    for (optind--; idx < size; idx++, optind++) {
        symdata->teams[idx].name = argv[optind];
        symdata->teams[idx].connected = 0;
        SLIST_INIT(&symdata->teams[idx].ai_ptr_head);
        SLIST_INIT(&symdata->teams[idx].egg_head);
    }
    return true;
}