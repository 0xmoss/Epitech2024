/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** main.c
*/

#include "main.hpp"

#include "core.hpp"
#include "arcade.hpp"
#include "arguments.hpp"
#include "tools.hpp"

bool launch(char *graphical, char *game)
{
    Arcade arcade;
    arcade.graphical(graphical);
    arcade.game(game);

    Core core(arcade.graphical(), arcade.game());
    core.Engine();

    return (true);
}

int main(int ac, char **argv)
{
    char *empty = manage::Set(EMPTY);
    char *option = manage::Set(EMPTY);
    char *graphical = manage::Set(EMPTY);
    char *game = manage::Set(EMPTY);

    if (arguments::correct(ac, argv) == true) {
        if (ac == 2) {
            option = argv[1];
            if (strcmp(empty, option) == 0 || strcmp(option, empty) == 0) {
                logs::help(argv[0]);
                return (0);
            } else {
                graphical = argv[1];
            }
        } else if (ac == 3) {
            graphical = argv[1];
            game = argv[2];
            if (arguments::exists(graphical) == false) {
                logs::display("graphical: path not found");
                return (84);
            }
            if (arguments::exists(game) == false) {
                logs::display("game: path not found");
                return (84);
            }
        }

        if (strcmp(graphical, empty) != 0) {
            logs::display("Starting Core");
            launch(graphical, game);
            logs::display("Stopping Core");
            return (0);
        }
    }
    logs::help(argv[0]);
    return (-1);
}
