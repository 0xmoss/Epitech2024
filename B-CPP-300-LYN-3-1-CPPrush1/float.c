/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush1-
** File description:
** float.c
*/

#include <stdio.h>

#include "float.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    float data;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this && args)
        this->data = (float)(va_arg(*args, double));
    else
        raise("Wrong pointer");
}

static void Float_dtor(FloatClass *this)
{
    return;
}

char *Float_str(FloatClass *this)
{
    int size = sizeof(float) + 32 + 1;
    char *str = malloc(size);

    if (this) {
        if (snprintf(str, size, "<%s (%f)>", this->base.__name__, \
            this->data) > 0)
            return (str);
        raise("Wrong pointer");
    }
    raise("Wrong pointer");
}

static const binary_operator_t Float_add(FloatClass *this, FloatClass *other)
{
    float result = 0.0;

    if (this && other) {
        result = ((FloatClass *)this)->data + ((FloatClass *)other)->data;
        Object *new_object = new(Float, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Float_sub(FloatClass *this, FloatClass *other)
{
    float result = 0.0;

    if (this && other) {
        result = ((FloatClass *)this)->data - ((FloatClass *)other)->data;
        Object *new_object = new(Float, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Float_mul(FloatClass *this, FloatClass *other)
{
    float result = 0.0;

    if (this && other) {
        result = ((FloatClass *)this)->data * ((FloatClass *)other)->data;
        Object *new_object = new(Float, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static const binary_operator_t Float_div(FloatClass *this, FloatClass *other)
{
    float result = 0.0;
    Object *new_object;

    if (this && other) {
        if (((FloatClass *)this)->data != 0)
            result = ((FloatClass *)this)->data / ((FloatClass *)other)->data;
        new_object = new(Float, result);
        return (new_object);
    }
    raise("Wrong pointer");
}

static bool Float_eq(FloatClass *this, FloatClass *other)
{
    if (this->data == other->data)
        return (true);
    return (false);
}

static bool Float_lt(FloatClass *this, FloatClass *other)
{
    if (this && other)
        if (this->data < other->data)
            return (true);
    return (false);
}

static bool Float_gt(FloatClass *this, FloatClass *other)
{
    if (this && other)
        if (this->data > other->data)
            return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .data = 0
};

const Class *Float = (const Class *)&_description;