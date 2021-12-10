/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** core.h
*/

#ifndef CORE_H
    #define CORE_H

    #include "phaseout.h"

    #include "build.h"

    size_t login(self_t *);

    size_t core(self_t *, server_t *);

    size_t arguments(self_t *, int, char **);

#endif /* CORE_H */
