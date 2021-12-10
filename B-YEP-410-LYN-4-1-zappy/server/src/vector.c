/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** vector
*/

#include "struct.h"

pos_t norm_vector(pos_t worldsize, pos_t pos)
{
    pos_t new_pos = {
        (pos.x < 0 ? worldsize.x : 0) + pos.x % worldsize.x,
        (pos.y < 0 ? worldsize.y : 0) + pos.y % worldsize.y
    };

    return new_pos;
}

pos_t apply_vector(pos_t worldsize, pos_t pos, pos_t vector)
{
    pos_t new_pos = {
        pos.x + vector.x,
        pos.y + vector.y
    };

    return norm_vector(worldsize, new_pos);
}