/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** optparser2
*/

#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include "prototypes.h"
#include "define.h"

bool parse_max_client_per_team(symdata_t *symdata, char *optarg)
{
    char *endptr = NULL;
    long long max_client_per_team = strtoll(optarg, &endptr, 10);

    if (endptr == NULL || *endptr != '\0' || 1 > max_client_per_team)
        return return_error(MAX_CLIENT_PER_TEAM_ERROR_STR);
    symdata->max_client_per_team = max_client_per_team;
    return true;
}

bool parse_time_unit_reciprocal(symdata_t *symdata, char *optarg)
{
    char *endptr = NULL;
    long long time_unit_reciprocal = strtoll(optarg, &endptr, 10);

    if (endptr == NULL || *endptr != '\0' ||
        2 > time_unit_reciprocal || time_unit_reciprocal > 10000)
            return return_error(FREQ_ERROR_STR);
    symdata->time_unit_reciprocal = time_unit_reciprocal;
    return true;
}

bool parse_opt(symdata_t *symdata, char **argv, size_t argc, int opt)
{
    switch (opt) {
        case 'p':
            return parse_port(symdata, optarg);
        case 'x':
            return parse_width(symdata, optarg);
        case 'y':
            return parse_height(symdata, optarg);
        case 'n':
            return parse_team_names(symdata, argv, argc, optind);
        case 'c':
            return parse_max_client_per_team(symdata, optarg);
        case 'f':
            return parse_time_unit_reciprocal(symdata, optarg);
        default:
            return false;
    }
    return false;
}

bool return_error(char const *string)
{
    fprintf(stderr, "\n%s\n", string);
    return false;
}