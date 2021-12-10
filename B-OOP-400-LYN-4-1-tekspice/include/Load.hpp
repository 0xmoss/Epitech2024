#ifndef _LOAD_HPP_
    #define _LOAD_HPP_

    #include <iostream>
    #include <stdio.h> 
    #include <string.h>
    #include <array> 

    #include "Nanotekspice.hpp"

    class Load
    {
        public:
            Load();
            ~Load();

            bool load_file(Nanotekspice *);

            bool load_data(Nanotekspice *, std::string);
            bool add_input_or_output(Nanotekspice *, std::string);
        private:
            bool first;
    };

    bool is_empty(std::ifstream &);

#endif /* _LOAD_HPP_ */