#ifndef _EDIT_HPP_
    #define _EDIT_HPP_

    #include <iostream>
    #include <stdio.h> 
    #include <string.h>
    #include <array> 

    #include "Nanotekspice.hpp"

    class Edit
    {
        public:
            Edit();
            ~Edit();

        bool change_input_value(Nanotekspice *, std::string );
    };

#endif /* _EDIT_HPP_ */