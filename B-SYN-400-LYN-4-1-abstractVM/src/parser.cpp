/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** main
*/

#include "abstractvm.hpp"
#include "checker.hpp"

abstractvm::abstractvm()
{
    return;
}

abstractvm::~abstractvm()
{
    return;
}


bool abstractvm::open()
{
    std::string str;

    if (abstractvm::path != EMPTY) {
        abstractvm::openned = true;
        std::ifstream file(abstractvm::path);
        for(; std::getline(file, str);) {
            try {
                abstractvm::parser(str);
            } catch (const Exception &e) {
                std::cerr << e.what() << std::endl;
                exit(84);
            }
        }
        file.close();
    }

    return (true);
}

bool abstractvm::handler(std::string command, std::string type)
{
    // std::cout << command << " : " << type << std::endl;
    if (command != END) {
        if (handler_0(command) == false &&
            handler_1(command, type) == false) {
            throw Exception(command, COMMAND_NOT_FOUND);
        }
    }

    return (true);
}

bool abstractvm::parser()
{
    checker checker;
    std::string command;
    std::vector<std::string> data;

    for (; command != END;) {
        std::getline(std::cin, command);
        data.push_back(command);
    }
    checker._data = data;
    checker.check(EMPTY);
    for (unsigned long i = 0; i < data.size(); i++)
        abstractvm::parser(data[i]);

    return (true);
}

bool abstractvm::parser(std::string line)
{
    std::string command;
    std::string type;

    if (!line.empty() && line.length() > 1) {
        if (line[0] != ';' || (line[0] == ';' && line[1] == ';')) {
            if (std::count(line.begin(), line.end(), ' ') == 1) {
                command = line.substr(0, line.find(" "));
                type = line.substr(command.length() + 1, line.length() - command.length());
            } else {
                command = line;
                type = UNKNOWN;
            }
            handler(command, type);
        }
    }

    return (true);
}

bool abstractvm::handler_0(std::string &command)
{
    std::string result;
    auto iter = this->mapped_functions_0.find(command);

    if (iter == abstractvm::mapped_functions_0.end())
        return (false);

    result = (this->*this->mapped_functions_0.at(command))();
    if (result != EMPTY)
        std::cout << result << std::endl;
    return (true);

}

bool abstractvm::handler_1(std::string &command, std::string type)
{
    std::string result;
    std::string data;
    size_t open_par = 0;
    size_t close_par = 0;
    auto iter = this->mapped_functions_1.find(command);

    if (iter == abstractvm::mapped_functions_1.end())
        return (false);

    if (std::count(type.begin(), type.end(), '(') == 1 && std::count(type.begin(), type.end(), ')') == 1) {
        open_par = type.find("(");
        close_par = type.find(")");
        data = type.substr(open_par + 1, close_par - open_par - 1);
        type = type.substr(0, open_par);
        result = (this->*this->abstractvm::mapped_functions_1.at(command))(type, data);
        if (result != EMPTY)
            std::cout << result << std::endl;
    }
    return (true);
}

