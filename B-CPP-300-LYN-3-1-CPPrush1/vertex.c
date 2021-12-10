/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (this && args) {
        x = va_arg(*args, int);
        y = va_arg(*args, int);
        z = va_arg(*args, int);
        this->x = x;
        this->y = y;
        this->z = z;
    } else
        raise("Wrong pointer");
}

static void Vertex_dtor(VertexClass *this)
{
    return;
}

char *Vertex_str(VertexClass *this)
{
    int size = 10 * 3 + 16 + 1;
    char *str = NULL;

    if (this) {
        str = malloc(size);
        if (snprintf(str, size, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z) > 0)
            return (str);
        raise("Wrong pointer");
    }
    raise("Wrong pointer");
}

Object *Vertex_add(const Object *this, const Object *other)
{
    Object *result;
    int x = 0;
    int y = 0;
    int z = 0;

    if (this && other) {
        x = ((VertexClass *)this)->x + ((VertexClass *)other)->x;
        y = ((VertexClass *)this)->y + ((VertexClass *)other)->y;
        z = ((VertexClass *)this)->z + ((VertexClass *)other)->z;
        result = new(Vertex, x, y, z);
        return (result);
    }
    raise("Wrong pointer");
}

Object *Vertex_sub(const Object *this, const Object *other)
{
    Object *result;
    int x = 0;
    int y = 0;
    int z = 0;

    if (this && other) {
        x = ((VertexClass *)this)->x - ((VertexClass *)other)->x;
        y = ((VertexClass *)this)->y - ((VertexClass *)other)->y;
        z = ((VertexClass *)this)->z - ((VertexClass *)other)->z;
        result = new(Vertex, x, y, z);
        return result;
    }
    raise("Wrong pointer");
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;