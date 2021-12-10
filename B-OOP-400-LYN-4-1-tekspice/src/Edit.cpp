#include "Edit.hpp"
#include "Logs.hpp"

#include "Vectors.hpp"
#include "Nanotekspice.hpp"

Edit::Edit()
{
    return;
}

Edit::~Edit()
{
    return;
}


bool Edit::change_input_value(Nanotekspice *nanotekspice, std::string modif)
{
    Logs logs;
    Vectors vectors;
    std::string key = modif.substr(0, modif.find("="));
    std::string value = modif.substr(key.length() + 1, modif.length() - key.length() - 1);
    int input = vectors.get_key(nanotekspice->input_keys_l, key);
    int output = vectors.get_key(nanotekspice->output_keys_l, key);

    if (input != -1) {
        if (value != "0" && value != "1") {
            logs.error("edit_value", value);
            return (false);
        }
        nanotekspice->input_values_l.at(input) = value;
        return (true);
    }
    if (output != -1) {
        nanotekspice->output_values_l.at(output) = value;
        return (true);
    }
    logs.error("edit_key", key);
    return (false);
}