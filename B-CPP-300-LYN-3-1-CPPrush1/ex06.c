/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** ex06
*/

#include "array.h"
#include "list.h"
#include "object.h"
#include "int.h"
#include "char.h"
#include "float.h"
#include "new.h"

int main(void)
{
    list_c_t list = NULL;

    add_element_at_back(&list, new(Array, 1, Int, 12));
    add_element_at_front(&list, new(Array, 1, Char, 'a'));
    add_element_at_front(&list, new(Array, 1, Float, 69.69));
    printf("Il y a %d element dans la liste\n", get_size(list));
    dump_my_list(list);
}