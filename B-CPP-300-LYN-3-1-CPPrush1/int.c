/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** int.c
*/

#include <stdio.h>

#include "int.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    int data;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this && args)
        this->data = (int)(va_arg(*args, int));
    else
        raise("Wrong pointer");
}

static void Int_dtor(IntClass *this)
{
    return;
}

char *Int_str(IntClass *this)
{
    int size = 16 + 1 + sizeof(int);
    char *str = malloc(size);

    if (this) {
        if (snprintf(str, size, "<%s (%d)>", this->base.__name__, \
        this->data) > 0)
            return str;
        raise("Wrong pointer");
    }
    raise("Wrong pointer");
}

static const binary_operator_t Int_add(IntClass *this, IntClass *other)
{
    int result = 0;

    if (this && other) {
        result = ((IntClass *)this)->data + ((IntClass *)other)->data;
        Object *new_object = new(Int, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Int_sub(IntClass *this, IntClass *other)
{
    int result = 0;

    if (this && other) {
        result = ((IntClass *)this)->data - ((IntClass *)other)->data;
        Object *new_object = new(Int, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Int_mul(IntClass *this, IntClass *other)
{
    int result = 0;

    if (this && other) {
        result = ((IntClass *)this)->data * ((IntClass *)other)->data;
        Object *new_object = new(Int, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Int_div(IntClass *this, IntClass *other)
{
    int result = 0;
    Object *new_object;

    if (this && other) {
        if (((IntClass *)this)->data != 0)
            result = ((IntClass *)this)->data / ((IntClass *)other)->data;
        new_object = new(Int, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static bool Int_eq(IntClass *this, IntClass *other)
{
    if (this && other) {
        if (this->data == other->data)
            return (true);
        return (false);
    }
    raise("Wrong pointer");
}

static bool Int_lt(IntClass *this, IntClass *other)
{
    if (this && other) {
        if (this->data < other->data)
            return (true);
        return (false);
    }
    raise("Wrong pointer");
}

static bool Int_gt(IntClass *this, IntClass *other)
{
    if (this && other) {
        if (this->data > other->data)
            return (true);
        return (false);
    }
    raise("Wrong pointer");
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .data = 0
};

const Class *Int = (const Class *)&_description;