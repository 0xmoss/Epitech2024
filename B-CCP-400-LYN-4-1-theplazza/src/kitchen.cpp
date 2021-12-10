/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "kitchen.hpp"
#include "commands.hpp"
#include "pool.hpp"

#include "self.hpp"

kitchen::kitchen(int multiplier, int cooks, int time, commands *commands_d,
    std::vector<std::string> pizzas, std::vector<std::string> sizes)
{
    this->multiplier_d = multiplier;
    this->cooks_d = cooks;
    this->time_d = time;
    this->pizza_queue_d = pizzas;
    this->size_queue_d = sizes;
    this->commands_d = commands_d;

    return;
}

kitchen::~kitchen()
{
    this->multiplier_d = 0;
    this->cooks_d = 0;
    this->time_d = 0;
    this->pizza_queue_d = {};
    this->size_queue_d = {};

    return;
}

int kitchen::multiplier()
{
    return (this->multiplier_d);
}

int kitchen::cooks()
{
    return (this->cooks_d);
}

int kitchen::time()
{
    return (this->time_d);
}

std::vector<std::string> kitchen::pizza_queue()
{
    return (this->pizza_queue_d);
}

std::vector<std::string> kitchen::size_queue()
{
    return  (this->size_queue_d);
}

bool kitchen::cook()
{
    pool func_pool;
    std::vector<std::thread> cooks_t;
    for (int i = 0; i < this->cooks_d; i++)
        cooks_t.push_back(std::thread(&pool::infinite_loop_func, &func_pool));
    for (auto i = this->pizza_queue_d.begin(); i != this->pizza_queue_d.end(); i++)
        func_pool.push(std::bind(&commands::launch, this->commands_d, this->commands_d->pizza));
    func_pool.close();
    for (unsigned int i = 0; i < cooks_t.size(); i++)
        cooks_t[i].join();
    return (true);
}
