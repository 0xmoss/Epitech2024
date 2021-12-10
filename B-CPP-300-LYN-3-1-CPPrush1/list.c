/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** list
*/

#include "list.h"
#include "array.h"
#include "list.h"
#include "object.h"
#include "int.h"
#include "char.h"
#include "float.h"
#include "new.h"

unsigned int get_size(list_c_t list)
{
    int i = 0;

    if (list == NULL)
        return 0;
    for (; list != NULL; list = list->next, i++);
    return i;
}

void add_element_at_back(list_c_t *list, Object *value)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *tmp = (*list);

    printf("Tu as ajouté un %s a la fin de ta liste\n", ((Class *)getitem((Container *)value, 0))->__name__);
    if (new_node == NULL)
        return;
    new_node->List = value;
    new_node->next = NULL;
    if (tmp == NULL) {
        (*list) = new_node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    return;
}

void add_element_at_front(list_c_t *list, Object *value)
{
    list_t *new_node = malloc(sizeof(list_t));

    printf("Tu as ajouté un %s au debut de ta liste\n", ((Class *)getitem((Container *)value, 0))->__name__);
    if (new_node == NULL)
        return;
    new_node->List = value;
    new_node->next = (*list);
    (*list) = new_node;
    return;
}

void dump_my_list(list_c_t list)
{
    for (int i = 0; list != NULL ; i++) {
        printf("La valeur de ce %s est %s\n", ((Class *)getitem(((Container *)list->List), 0))->__name__, str(getitem(((Container *)list->List), 0)));
        list = list->next;
    }
}