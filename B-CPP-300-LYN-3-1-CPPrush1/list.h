/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** ex06
*/

#include "object.h"

#ifndef EX06_H_
#define EX06_H_

typedef struct list_s
{
    struct list_s *next;
    Object *List;
}list_t;

typedef list_t *list_c_t;

unsigned int get_size(list_c_t list);
void add_element_at_back(list_c_t *list, Object *value);
void add_element_at_front(list_c_t *list, Object *value);
void dump_my_list(list_c_t list);

#endif /* !EX06_H_ */