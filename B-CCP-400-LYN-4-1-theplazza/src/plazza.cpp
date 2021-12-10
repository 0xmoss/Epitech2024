/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "plazza.hpp"

#include "kitchen.hpp"

self_t *builder()
{
    self_t *self = (self_t *)malloc(sizeof(self_t));

    self->cooks_d = 0;
    self->multiplier_d = 0;
    self->time_d = 0;

    return (self);
}

bool arguments(int ac, char **argv, self_t *self)
{
    if (ac == 4) {
        self->multiplier_d = atoi(argv[1]);
        self->cooks_d = atoi(argv[2]);
        self->time_d = atoi(argv[3]);

        return (true);
    }

    return (false);
}

bool kitchen_builder(int multiplier, int cooks, int time, commands *commands, std::vector<std::string> pizzas, std::vector<std::string> sizes)
{
    pid_t child = fork();

    if (child == -1) {
        std::cout << "fork failed" << std::endl;
    } else if (child == 0) {
        std::cout << "[ " << getpid() << " ]  " << "kitchen" << std::endl;
        kitchen kitchen(multiplier, cooks, time, commands, pizzas, sizes);
        kitchen.cook();
        exit(0);
    } else {
        child = wait(NULL);
            std::cout << "back to parent" << std::endl;
    }

    return (true);
}

bool queuer(commands *commands)
{
    size_t limit = 2 * commands->self->cooks_d;
    std::vector<std::string> pizza_queue_d = {};
    std::vector<std::string> size_queue_d = {};

    for (int i = 0; i < commands->count; i++) {
        if (limit > 0) {
            pizza_queue_d.push_back(commands->pizza);
            size_queue_d.push_back(commands->size);
            limit--;
        } else {
            kitchen_builder(
                commands->self->multiplier_d,
                commands->self->cooks_d,
                commands->self->time_d,
                commands,
                pizza_queue_d,
                size_queue_d
            );
            pizza_queue_d.clear();
            size_queue_d.clear();
            limit = 2 * commands->self->cooks_d;
        }
    }
    kitchen_builder(
        commands->self->multiplier_d,
        commands->self->cooks_d,
        commands->self->time_d,
        commands,
        pizza_queue_d,
        size_queue_d
    );

    return (true);
}

int main(int ac, char **argv)
{
    self_t *self = builder();
    std::string pizza;
    std::string size;
    std::string count;

    commands commands(self);

    if (arguments(ac, argv, self) == true) {
        for (;;) {
            std::cin >> pizza >> size >> count;
            if (commands.check_pizza(pizza) == true) {
                if (commands.check_size(size) == true) {
                    if (commands.check_count(count) == true) {
                        commands.pizza = pizza;
                        commands.size = size;
                        if (count[count.length() - 1] == ';')
                            commands.count = stoi(count.substr(1, size.length() - 2));
                        else
                            commands.count = stoi(count.substr(1, size.length()));
                        queuer(&commands);
                    } else {
                        std::cout << "Pizza count invalid" << std::endl;
                    }
                } else {
                    std::cout << "Pizza size invalid" << std::endl;
                }
            } else {
                std::cout << "Pizza name invalid" << std::endl;
            }
        }
        return (0);
    }
    return (84);
}
