/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-
** File description:
** checker
*/

#ifndef CHECKER_HPP

    #define CHECKER_HPP

    class checker
    {
        public:
            checker();
            ~checker();

            std::vector<std::string> _data;

            bool check(std::string);
            bool check_path(void);
            bool check_exit(void);
            bool load(void);
            bool check_command(size_t);
            bool check_type(size_t);
            bool check_data(std::string, std::string);
            bool number(std::string);
            bool search_command(std::string, std::string, std::string);
            bool search_type(std::string);
            bool errors(std::string);

        private:
            std::vector<std::string> _command = {
                "pop",
                "dump",
                "clear",
                "dup",
                "swap",
                "add",
                "sub",
                "mul",
                "div",
                "mod",
                "print",
                "exit",
                "push",
                "assert",
                "load",
                "store",
                ";;"
            };
            std::vector<bool> _require = {
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                true,
                true,
                true,
                true,
                false
            };
            std::array<std::string, 6> _type = {
                "int8",
                "int16",
                "int32",
                "float",
                "double",
                "bigdecimal"
            };
            std::string _path = EMPTY;
    };

#endif /* CHECKER_HP */
