/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-
** File description:
** c_str.c
*/

#include "string.h"

const char *c_str(const string_t *this)
{
   if (!this || !this->str)
      return(NULL);
   return(this->str);
}