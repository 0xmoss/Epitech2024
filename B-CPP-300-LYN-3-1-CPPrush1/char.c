/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "object.h"
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char    data;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this && args)
        this->data = (char)(va_arg(*args, int));
    else
        raise("Wrong pointer");
}

static void Char_dtor(CharClass *this)
{
    return;
}

char *Char_str(CharClass *this)
{
    int size = 32 + 4 + 1;
    char *str = malloc(size);

    if (this) {
        if (snprintf(str, size, "<%s (%c)>", this->base.__name__, \
        this->data) > 0)
            return (str);
        raise("Wrong pointer");
    }
    raise("Wrong pointer");
}

Object *Char_add(const Object *this, const Object *other)
{
    Object *new_object;
    int res = 0;

    if (this && other) {
        new_object = new(Char);
        printf("this = %d\n other = %d\n", res, ((CharClass *)this)->data, ((CharClass *)other)->data);
        res = ((CharClass *)this)->data + ((CharClass *)other)->data;
        printf("%d\n", res);
        ((CharClass *)new_object)->data = res;
        return (new_object);
    }
    raise("Wrong pointer");

}

Object *Char_sub(const Object *this, const Object *other)
{
    Object *new_object;
    char res = 0;

    if (this && other) {
        res = ((CharClass *)this)->data - ((CharClass *)other)->data;
        new_object = new(Char, res);
        return (new_object);
    }
    raise("Wrong pointer");
}

Object *Char_mul(const Object *this, const Object *other)
{
    Object *new_object;
    char res = 0;

    if (this && other) {
        res = ((CharClass *)this)->data * ((CharClass *)other)->data;
        new_object = new(Char, res);
        return (new_object);
    }
    raise("Wrong pointer");
}

Object *Char_div(const Object *this, const Object *other)
{
    Object *new_object;
    char res = 0;

    if (this && other) {
        if (((CharClass *)other)->data != 0)
            res = ((CharClass *)this)->data / ((CharClass *)other)->data;
        new_object = new(Char, res);
        return (new_object);
    }
    raise("Wrong pointer");
}

bool Char_eq(const Object *this, const Object *other)
{
    if (this && other)
        return (((CharClass *)this)->data == ((CharClass *)other)->data);
    raise("Wrong pointer");
}

bool Char_gt(const Object *this, const Object *other)
{
    if (this && other)
        return (((CharClass *)this)->data > ((CharClass *)other)->data);
    raise("Wrong pointer");
}

bool Char_lt(const Object *this, const Object *other)
{
    if (this && other)
        return (((CharClass *)this)->data < ((CharClass *)other)->data);
    raise("Wrong pointer");
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .data = 0
};

const Class *Char = (const Class *)&_description;
