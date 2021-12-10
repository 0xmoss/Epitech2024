/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** wp_text.c
*/

#include "flags.h"
#include "includes.h"

int check_wp_text(int flags)
{
    if ((flags & WP_TEXT) != 0) {
        printf("WP_TEXT");
        flags -= WP_TEXT;
    }
    return (flags);
}
