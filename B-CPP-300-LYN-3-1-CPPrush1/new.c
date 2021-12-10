/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** new
*/

#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *new_object;
    va_list ap;

    va_start(ap, class);
    new_object = va_new(class, &ap);
    va_end(ap);
    return new_object;
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *new_object = malloc(class->__size__);
    if (new_object == NULL)
        raise("Out of memory");
    memcpy(new_object, class, class->__size__);
    if (((Class *)new_object)->__ctor__ != NULL)
        ((Class *)new_object)->__ctor__(new_object, ap);
    return new_object;
}

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__) {
        ((Class *)ptr)->__dtor__(ptr);
    } if (ptr)
        free(ptr);
}