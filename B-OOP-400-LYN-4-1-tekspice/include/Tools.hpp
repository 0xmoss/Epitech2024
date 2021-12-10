#ifndef _TOOLS_HPP_
    #define _TOOLS_HPP_

    #include <iostream>
    #include <sstream>
    #include <string>
    #include <fstream>

    class Tools
    {
        public:
            Tools();
            ~Tools();

            std::string f_line(std::string, int);
            int f_count(std::string);

            bool check_command(std::string);

            int count_char(std::string, char);
            int strlen(char *);
            char *phase_insert(char *, char);
            char **split(std::string, char);
    };

#endif /* _TOOLS_HPP_ */