/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** content.h
*/

#include "phaseout.h"

#include "includes.h"

#ifndef CONTENT_H
    #define CONTENT_H

    size_t x64_content_get(struct stat, int, char *);
    size_t x64_destroyer(size_t, char *);

    size_t x32_content_get(struct stat, int, char *);
    size_t x32_destroyer(size_t, char *);

#endif /* CONTENT_H */
