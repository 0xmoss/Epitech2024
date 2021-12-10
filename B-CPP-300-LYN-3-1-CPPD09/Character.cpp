/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-
** File description:
** Character.cpp
*/

#include <iostream>
#include <string>

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->name = name;
    this->level = level;

    std::cout << this->name << " Created" << std::endl;
}

Character::~Character()
{
    return;
}

std::string const & Character::getName() const
{
    return(this->name);
}

int Character::getLvl() const
{
    return(this->level);
}

int Character::getPv() const
{
    return(this->pv);
}

int Character::getPower() const
{
    return(this->pm);
}

int Character::getForce() const
{
    return(this->force);
}

int Character::getEndurance() const
{
    return(this->endurance);
}

int Character::getIntelligence() const
{
    return(this->intelligence);
}

int Character::getEsprit() const
{
    return(this->esprit);
}

int Character::getAgilite() const
{
    return(this->agilite);
}

void Character::changePv(int value)
{
    this->pv += value;
    if (this->pv < 0)
        this->pv = 0;
    else if (this->pv > lifeMax)
        this->pv = lifeMax;
}

void Character::changePm(int value)
{
    this->pm += value;
    if (this->pm < 0)
        this->pm = 0;
    else if (this->pm > movMax)
        this->pm = movMax;
}

int Character::CloseAttack()
{
    if (actionCost(this->costClose)) {
        std::cout << this->name << " strikes with a " << weaponClose << std::endl;
        return(this->atkClose + this->*bonusCloseAttack);
    }
    display("out of power");
    return(0);
}

int Character::RangeAttack()
{
    if (actionCost(this->costRange)) {
        std::cout << this->name << " tosses a " << weaponRange << std::endl;
        return(this->atkRange + this->*bonusRangeAttack);
    }
    display("out of power");
    return(0);
}

void Character::Heal()
{
    if (actionCost(this->costPv)) {
        changePv(this->restorePv);
        display("takes a potion");
        return;
    }
    display("out of power");
}

void Character::RestorePower()
{
    if (actionCost(this->costPm)) {
        changePm(this->restorePm + this->*bonusRestorePm);
        display("eats");
        return;
    }
    display("out of power");
}

void Character::TakeDamage(int damage)
{
    if (damage >= 0) {
        changePv(-damage);
        if (this->pv == 0)
            display("out of combat");
        else
            std::cout << this->name << " takes " << damage <<
            " damage" << std::endl;
    }
}

bool Character::actionCost(int cost)
{
    if (this->pm >= cost) {
        changePm(-cost);
        return(true);
    }
    return(false);
}

void Character::display(std::string message) const
{
    std::cout << this->name << " " << message << std::endl;
}