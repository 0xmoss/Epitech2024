/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Toy.cpp
*/

#include <iostream>

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy")
{
    return;
}

Toy::Toy(ToyType type, std::string const & name, std::string const & ascii) : 
	type(type), name(name), picture(ascii)
{
    return;
}

Toy::Toy(Toy const &toy) : type(toy.type), name(toy.name), picture(toy.picture)
{
    return;
}

Toy::~Toy()
{
    return;
}

int Toy::getType() const
{
	return(this->type);
}

std::string const & Toy::getName() const
{
	return(this->name);
}

std::string const & Toy::getAscii() const
{
	return(this->picture.data);
}

void Toy::setName(std::string const & name)
{
	this->name = name;
	return;
}

bool Toy::setAscii(std::string const &ascii)
{
    if (this->picture.getPictureFromFile(ascii)) {
        return(true);
	}
	this->error.setType(Error::PICTURE);
	return (false);
}

void Toy::display(const std::string message)
{
	(void)message;
	this->error.setType(Error::ERROR);
	return;
}

Toy::Error const & Toy::getLastError() const
{
	return(this->error);
}

Toy &Toy::operator = (Toy const &toy)
{
	this->type = toy.type;
	this->name = toy.name;
	this->picture = toy.picture;

	return(*this);
}

Toy &Toy::operator << (std::string const & ascii)
{
	this->picture.data = ascii;

	return(*this);
}

Toy::Error::Error() : type(UNKNOWN)
{
    return;
}

void Toy::Error::setType(ErrorType type)
{
	this->type = type;
}

std::ostream &operator << (std::ostream &os, Toy const &toy)
{
	return(os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}
