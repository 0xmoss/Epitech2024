/*
** EPITECH PROJECT, 2019
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** open.c
*/

#include "flags.h"

#include "tools.h"
#include "check.h"
#include "content.h"
#include "truncated.h"

#include "phaseout.h"
#include "includes.h"
#include "open.h"

int x64_open_file(char *path)
{
    struct stat stats;
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        close(fd);
        return (False);
    }
    if (fstat(fd, &stats) == -1) {
        close(fd);
        return (False);
    }
    if (x64_content_get(stats, fd, path) == False) {
        close(fd);
        return (False);
    }
    return (True);
}
