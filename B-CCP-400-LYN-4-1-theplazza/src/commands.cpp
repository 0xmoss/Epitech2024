/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "commands.hpp"

commands::commands(self_t *self)
{
    this->self = self;

    return;
}

commands::~commands()
{
    return;
}

bool commands::check_pizza(std::string pizza)
{
    // std::cout << tools::get_pizza_type_value(pizza) << std::endl;

    if (tools::get_pizza_type_value(pizza) != -1)
        return (true);
    return (false);
}

bool commands::check_size(std::string size)
{
    // std::cout << tools::get_pizza_size_value(size) << std::endl;
    
    if (tools::get_pizza_size_value(size) != -1)
        return (true);
    return (false);
}

bool commands::check_count(std::string size)
{
    if (size.length() > 1) {
        if (size[0] == 'x') {
            for (int i = 1; i < size.length(); i++) {
               if (size[i] < 48 && size[i] > 57)
                    return (false);
            }
            return (true);
        }
    }

    return (false);
}

bool commands::launch(std::string type)
{
    if (type == "regina")
        commands::regina();
    else if (type == "margarita")
        commands::margarita();
    else if (type == "americana")
        commands::americana();
    else if (type == "fantasia")
        commands::fantasia();

    return (true);
}

void commands::estimate(int time)
{
    std::cout << "Estimated time: " << time << "ms" << std::endl;
}

void commands::received(std::string type)
{
    std::cout << "Recieved " << type << " " << this->size << std::endl;
}

void commands::margarita()
{
    this->recipe = this->doe + this->tomato + this->gruyere;
    this->bake = this->self->time_d * this->recipe;

    std::cout << this->self->time_d << std::endl;
    commands::estimate(this->bake);
    std::this_thread::sleep_for(std::chrono::milliseconds(this->bake));
    commands::received("margarita");
}

void commands::regina()
{
    this->recipe = this->tomato + this->doe + this->gruyere + this->ham + this->mushrooms;
    this->bake = this->self->time_d * this->recipe;

    commands::estimate(this->bake);
    std::this_thread::sleep_for(std::chrono::milliseconds(this->bake));
    commands::received("regina");
}

void commands::americana()
{
    this->recipe = this->tomato + this->doe + this->gruyere + this->steak;
    this->bake = this->self->time_d * this->recipe;

    commands::estimate(this->bake);
    std::this_thread::sleep_for(std::chrono::milliseconds(this->bake));
    commands::received("americana");
}

void commands::fantasia()
{
    this->recipe = this->tomato + this->doe + this->eggplant + this->goat_cheese;
    this->bake = this->self->time_d * this->recipe;

    commands::estimate(this->bake);
    std::this_thread::sleep_for(std::chrono::milliseconds(this->bake));
    commands::received("fantasia");
}
