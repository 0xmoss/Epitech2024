/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-
** File description:
** ex00.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
	printf("----\n");
	this->m_name = malloc(8);
	strcpy(this->m_name, "Cthulhu");
	this->m_power = 42;
	printf("Building Cthulhu\n");
}

static void koala_initializer(koala_t *this, char *name, char legend)
{
	cthulhu_initializer(&this->m_parent);
	this->m_parent.m_name = name;
	this->m_parent.m_power = (legend ? 42 : 0);
	this->m_is_a_legend = legend;
	printf("Building %s\n", this->m_parent.m_name);
}

cthulhu_t *new_cthulhu()
{
	cthulhu_t *obj = malloc(sizeof(cthulhu_t));

	cthulhu_initializer(obj);
	return(obj);
}

void print_power(cthulhu_t *this)
{
	printf("Power => %i\n", this->m_power);
}

void attack(cthulhu_t *this)
{
	if (this->m_power >= 42) {
		this->m_power -= 42;
		printf("%s attacks and destroys the city\n", this->m_name);
	} else
		printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
	this->m_power += 42000;
	printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char legend)
{
	koala_t *obj = malloc(sizeof(koala_t));

	koala_initializer(obj, name, legend);
	return(obj);
}

void eat(koala_t *this)
{
	this->m_parent.m_power += 42;
	printf("%s eats\n", this->m_parent.m_name);
}