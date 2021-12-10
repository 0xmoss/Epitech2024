/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** core.cpp
*/

#include "core.hpp"

#include "arcade.hpp"
#include "tools.hpp"

Core::Core(char *graphical, char *game)
{
    this->graphical_data = graphical;
    this->game_data = game;

    return;
}

Core::~Core()
{
    return;
}

bool Core::Engine()
{
    Core::Open(this->graphical_data);

    return (false);
}

bool Core::Open(char *graphical)
{
    char *error;
    void *handler;
    void (* menu)(void);

    logs::display("Openning graphical...");
    logs::display(graphical);

    handler = dlopen(graphical, RTLD_LAZY);
    if (!handler) {
        logs::display("Fail to open graphical");
        return (false);
    }
    *(void **) (&menu) = (void *)dlsym(handler, "Display");
    if ((error = dlerror()) != NULL) {
        logs::display(error);
        return (false);
    }
    (*menu)();
    dlclose(handler);
    return (true);
}
