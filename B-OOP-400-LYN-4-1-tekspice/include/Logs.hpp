#ifndef _LOGS_HPP_
    #define _LOGS_HPP_

    #include <iostream>

    class Logs
    {
        public:
            Logs();
            ~Logs();

            void prompt();
            void display(std::string);
            void error(std::string, std::string);
    };

#endif /* _LOGS_HPP_ */