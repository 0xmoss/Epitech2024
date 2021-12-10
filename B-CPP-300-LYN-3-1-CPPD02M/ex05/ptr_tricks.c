/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-
** File description:
** ptr_tricks.c
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    return (ptr2 - ptr1);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t what;

    return (void*)(member_ptr) - ((void *)(&what.member) - (void *)(&what));
}