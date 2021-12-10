#include "abstractvm.hpp"
#include "checker.hpp"

bool checker::check_path(void)
{
    if (access(checker::_path.c_str(), F_OK) != -1)
        return (true);
    throw Exception(std::string(checker::_path), FILE_NOT_FOUND);
}

bool checker::check_exit(void)
{
    for (size_t i = 0; i < checker::_data.size(); i++)
        if (checker::_data[i] == "exit")
            return (true);
    throw Exception("'exit'", EXIT);
}

bool checker::check_data(std::string type, std::string data)
{
    long dot = 0;

    if (data.empty() == false)  {
        if (checker::number(data) == false)
            throw Exception(data, INVALID_TYPE_VALUE);
        dot = std::count(data.begin(), data.end(), '.');
        if (dot >= 0 && dot <= 1) {
            if (dot == 1 && (type == "float" ||
                        type == "double" ||
                        type == "bigdecimal"))
                return (true);
            else if (dot == 0 && (type.find("int", 0) == 0 ||
                        type.find("double", 0) == 0 ||
                        type.find("float", 0) == 0))
                return (true);
            throw Exception(data, WRONG_TYPE_VALUE);
        }
        throw Exception(data, BAD_FORMAT_TYPE_VALUE);
    }

    throw Exception(data, INVALID_TYPE_VALUE);
}

bool checker::number(std::string data)
{
    for (size_t i = 0; i < data.length(); i++) {
        if (data[i] != '.' && (data[i] < '0' || data[i] > '9'))
            return (false);
    }

    return (true);
}

bool checker::search_command(std::string command, std::string type, std::string data)
{
    for (size_t i = 0; i < checker::_command.size(); i++) {
        if (checker::_command[i] == command) {
            if (checker::_require[i] == false && type == EMPTY)
                return (true);
            else if (checker::_require[i] == true && type != EMPTY)
                return (check_data(type, data));
            else {
                if (checker::_require[i] == false && type != EMPTY)
                    throw Exception(command, COMMAND_TYPE_IS_NOT_REQUIRED);
                else
                    throw Exception(command, COMMAND_TYPE_IS_REQUIRED);
            }
        }
    }
    throw Exception(command, COMMAND_NOT_FOUND);
}

bool checker::search_type(std::string type)
{
    for (size_t i = 0; i < 6; i++)
        if (checker::_type[i] == type)
            return (true);
    throw Exception(type, TYPE_NOT_FOUND);
}

bool checker::errors(std::string content)
{
    std::string line = content;
    std::string command = EMPTY;
    std::string type = EMPTY;
    std::string data = EMPTY;
    long spaces = std::count(line.begin(), line.end(), ' ');
    long open_count = std::count(line.begin(), line.end(), '(');
    long close_count = std::count(line.begin(), line.end(), ')');
    size_t open_par = 0;
    size_t close_par = 0;

    if (spaces >= 0 && spaces <= 1) {
        if (spaces == 1) {
            if (open_count == 1 && close_count == 1) {
                command = line.substr(0, line.find(" "));
                type = line.substr(command.length() + 1, line.length() - command.length());
                open_par = type.find("(");
                close_par = type.find(")");
                data = type.substr(open_par + 1, close_par - open_par - 1);
                type = type.substr(0, open_par);
                checker::search_type(type);
            } else
                throw Exception(line, PARENTHESE_MISSING);
        } else
            command = line;
        checker::search_command(command, type, data);
        return (true);
    }
    throw Exception(line, LEXICAL);
}

bool checker::load(void)
{
    std::string line;
    std::ifstream file(checker::_path);

    for (; std::getline(file, line);)
        if (line.empty() == false && line.length() > 1)
            if (line[0] != ';' || (line[0] == ';' && line[1] == ';'))
                checker::_data.push_back(line);

    return (true);
}

bool checker::check(std::string path)
{
    try {
        if (path != EMPTY) {
            checker::_path = path;
            checker::check_path();
            checker::load();
        }
        checker::check_exit();
        for (size_t i = 0; i < checker::_data.size(); i++) {
            checker::errors(checker::_data[i]);
        }
    } catch (const Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }

    return (true);
}

checker::checker()
{
    return;
}

checker::~checker()
{
    return;
}
