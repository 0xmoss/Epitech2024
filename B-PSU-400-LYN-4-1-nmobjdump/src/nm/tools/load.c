/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump--master
** File description:
** utils.c
*/

#include "nm.h"

void *load(char *fn, int *fd, long *size)
{
    void *data;

    if (access(fn, F_OK) != 0) {
        printf("%s: File not found\n", fn);
        return (NULL);
    }
    if (access(fn, R_OK) == -1) {
        printf("Permission denied\n");
        return (NULL);
    }
    (*fd) = open(fn, O_RDONLY, 0);
    if ((*fd) == -1) {
        printf("No such file\n");
        return (NULL);
    }
    (*size) = lseek((*fd), 0, SEEK_END);
    if ((*fd) == -1) {
        printf("lseek failed\n");
        return (NULL);
    }
    data = mmap(NULL, (*size), PROT_READ, MAP_SHARED, (*fd), 0);
    if (data == MAP_FAILED && (*size) > 0) {
        close((*fd));
        printf("Not an ordinary file\n");
        return (MAP_FAILED);
    }

    return (data);
}

