#include "Load.hpp"

#include "Tools.hpp"
#include "Contains.hpp"
#include "Nanotekspice.hpp"
#include "Vectors.hpp"
#include "Logs.hpp"

Load::Load()
{
    this->first = true;

    return;
}

Load::~Load()
{
    return;
}

bool is_chipset(std::string type)
{
    std::array<std::string, 15> types = {
        "2716",
        "4001",
        "4008",
        "4011",
        "4013",
        "4017",
        "4030",
        "4040",
        "4069",
        "4071",
        "4081",
        "4094",
        "4512",
        "4514",
        "4801"
    };

    for (int i = 0; i < 15; i++) {
        if (type == types[i])
            return (true);
    }

    return (false);
}

bool is_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool Load::load_data(Nanotekspice *nanotekspice, std::string link)
{
    Vectors vectors;
    Logs logs;

    bool input = true;

    std::string key = link.substr(0, link.find(" "));
    std::string value = link.substr(key.length() + 1, link.length() - key.length());

    std::string pin_key;
    std::string pin_value;
    std::string gate_key;
    std::string gate_value;

    try {
        if (is_chipset(key) == false) {
            if (key == "input") {
                nanotekspice->input_keys_l.push_back(value);
            } else if (key == "output") {
                nanotekspice->output_keys_l.push_back(value);
            } else if (key == "clock") {
                nanotekspice->clock_keys_l.push_back(value);
            } else {
                if (this->first == true) {
                    nanotekspice->input_values_l.assign(vectors.count(nanotekspice->input_keys_l), "U");
                    nanotekspice->input_pins_l.assign(vectors.count(nanotekspice->input_keys_l), "U");

                    nanotekspice->output_values_l.assign(vectors.count(nanotekspice->output_keys_l), "U");
                    nanotekspice->output_pins_l.assign(vectors.count(nanotekspice->output_keys_l), "U");

                    this->first = false;
                }

                if (Contains_char(link, ':') == true) {
                    pin_key = key.substr(0, key.find(":"));
                    pin_value = key.substr(pin_key.length() + 1, key.length() - pin_key.length());
                    gate_key = value.substr(0, value.find(":"));
                    gate_value = value.substr(gate_key.length() + 1, value.length() - gate_key.length());
                    
                    if (pin_key != nanotekspice->name) {
                        // KEY

                        // VALUES
                        if (vectors.get_key(nanotekspice->input_keys_l, pin_key) > -1) {
                            nanotekspice->input_values_l.at(vectors.get_key(nanotekspice->input_keys_l, pin_key)) = pin_value;
                        } else if (vectors.get_key(nanotekspice->output_keys_l, pin_key) != -1) {
                            nanotekspice->output_values_l.at(vectors.get_key(nanotekspice->output_keys_l, pin_key)) = pin_value;
                        } else {
                            logs.error("input_name", pin_key);
                            return (false);
                        }
                        // PINS
                        if (vectors.get_key(nanotekspice->input_keys_l, pin_key) > -1) {
                            nanotekspice->input_pins_l.at(vectors.get_key(nanotekspice->input_keys_l, pin_key)) = gate_value;
                        } else if (vectors.get_key(nanotekspice->output_keys_l, pin_key) > -1) {
                            nanotekspice->output_pins_l.at(vectors.get_key(nanotekspice->output_keys_l, pin_key)) = gate_value;
                        } else {
                            logs.error("input_name", gate_key);
                            return (false);
                        }
                    } else if (gate_key != nanotekspice->name) {
                        // KEY

                        // VALUES
                        if (vectors.get_key(nanotekspice->input_keys_l, gate_key) > -1) {
                            nanotekspice->input_values_l.at(vectors.get_key(nanotekspice->input_keys_l, gate_key)) = pin_value;
                        } else if (vectors.get_key(nanotekspice->output_keys_l, gate_key) > -1) {
                            nanotekspice->output_values_l.at(vectors.get_key(nanotekspice->output_keys_l, gate_key)) = gate_value;
                        } else {
                            logs.error("output_name", gate_key);
                            return (false);
                        }
                        // PINS
                        if (vectors.get_key(nanotekspice->input_keys_l, gate_key) > -1) {
                            nanotekspice->input_pins_l.at(vectors.get_key(nanotekspice->input_keys_l, gate_key)) = gate_value;
                        } else if (vectors.get_key(nanotekspice->output_keys_l, gate_key) > -1) {
                            nanotekspice->output_pins_l.at(vectors.get_key(nanotekspice->output_keys_l, gate_key)) = pin_value;
                        } else {
                            logs.error("output_name", gate_key);
                            return (false);
                        }
                    }
                }
            }
        } else {
            nanotekspice->name = value;
            nanotekspice->chipset = key;
        }
    } catch (...) {
        return (true);
    }

    return (true);
}

bool Load::load_file(Nanotekspice *nanotekspice)
{
    Tools tools;
    Logs logs;
    Vectors vectors;

    int lines = tools.f_count(nanotekspice->filename());
    std::string line = "";

    for (int i = 0; i < lines; i++) {
        line = tools.f_line(nanotekspice->filename(), i);
        if (line != "\n" && !line.empty()) {
            if (line[0] != '#' && Contains_char(line, ' ') == true) {
                if (Load::load_data(nanotekspice, line) == false)
                    return (false);
            }
        }
    }

    return (true);
}