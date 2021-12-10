/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

#include "Interface.hpp"
#include "Logs.hpp"
#include "Transform.hpp"
#include "Table.hpp"
#include "Vectors.hpp"

// CHIPSETS
#include "2716.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4030.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "4094.hpp"
#include "4512.hpp"
#include "4514.hpp"
#include "4801.hpp"

#include "True.hpp"
#include "False.hpp"

Factory::Factory()
{
    return;
}

Factory::~Factory()
{
    return;
}

std::unique_ptr<nts::IComponent> Factory::create(std::string const &type, Factory *factory)
{
    Logs logs;

    _2716_ C2716(factory);
    _4001_ C4001(factory);
    _4008_ C4008(factory);
    _4011_ C4011(factory);
    _4013_ C4013(factory);
    _4017_ C4017(factory);
    _4030_ C4030(factory);
    _4040_ C4040(factory);
    _4069_ C4069(factory);
    _4071_ C4071(factory);
    _4081_ C4081(factory);
    _4094_ C4094(factory);
    _4512_ C4512(factory);
    _4514_ C4514(factory);
    _4801_ C4801(factory);

    True CTrue(factory);
    True CFalse(factory);

    if (type == "2716") {
        C2716.simulate(0);
    }

    if (type == "4001") {
        C4001.simulate(0);
    }

    if (type == "4008") {
        C4008.simulate(0);
    }

    if (type == "4011") {
        C4011.simulate(0);
    }

    if (type == "4013") {
        C4013.simulate(0);
    }

    if (type == "4017") {
        C4017.simulate(0);
    }

    if (type == "4030") {
        C4030.simulate(0);
    }

    if (type == "4040") {
        C4040.simulate(0);
    }

    if (type == "4069") {
        C4069.simulate(0);
    }

    if (type == "4071") {
        C4071.simulate(0);
    }

    if (type == "4081") {
        C4081.simulate(0);
    }

    if (type == "4094") {
        C4094.simulate(0);
    }

    if (type == "4512") {
        C4512.simulate(0);
    }

    if (type == "4514") {
        C4514.simulate(0);
    }

    if (type == "4801") {
        C4801.simulate(0);
    }

    if (type == "true") {
        CTrue.simulate(0);
    }

    if (type == "false") {
        CFalse.simulate(0);
    }

    return (0);
}

std::string Factory::simulate_or(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.or_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_and(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.and_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_nand(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.nand_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_nor(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.nor_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_xor(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.nor_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_sum(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.sum_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}

std::string Factory::simulate_not(std::string pin_1, std::string pin_2)
{
    Table table;
    Vectors vectors;

    std::string result = "0";

    result = transform::btos(
        table.not_gate(
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_1
                )),
            transform::stob(
                vectors.click(
                    this->input_pins_l, this->input_values_l, pin_2
                ))
            )
        );

    return (result);
}