/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>

#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    int x = 0;
    int y = 0;

    if (this) {
        x = va_arg(*args, int);
        y = va_arg(*args, int);
        this->x = x;
        this->y = y;
    } else
        raise("Wrong pointer");
}

static void Point_dtor(PointClass *this)
{
    return;
}

static const binary_operator_t Point_add(PointClass *this, PointClass *other)
{
    int new_x = 0;
    int new_y = 0;
    Object *new_object;

    if (this && other) {
        new_x = ((PointClass *)this)->x + ((PointClass *)other)->x;
        new_y = ((PointClass *)this)->y + ((PointClass *)other)->y;
        new_object = new(Point, new_x, new_y);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Point_sub(PointClass *this, PointClass *other)
{
    int new_x = 0;
    int new_y = 0;
    Object *new_object;

    if (this && other) {
        new_x = ((PointClass *)this)->x - ((PointClass *)other)->x;
        new_y = ((PointClass *)this)->y - ((PointClass *)other)->y;
        new_object = new(Point, new_x, new_y);
        return (new_object);
    }
    raise("Wrong pointer");
}

char *Point_str(PointClass *this)
{
    int size = 12 + 10 * 2 + 1;
    char *str = malloc(size);

    if (this) {
        if (snprintf(str, size, "<Point (%d, %d)>", this->x, this->y) > 0)
            return (str);
        raise("Wrong pointer");
    }
    raise("Wrong pointer");
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;