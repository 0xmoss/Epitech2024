#ifndef _INTERFACE_HPP_
    #define _INTERFACE_HPP_

    #include "Nanotekspice.hpp"
    #include "Vectors.hpp"
    #include "Table.hpp"

    #include <iostream>
    #include <vector>

    namespace nts
    {
        enum Tristate
        {
            UNDIFINED = (-true),
            TRUE = true,
            FALSE = false
        };

        enum types_t
        {
            type_2716,
            type_4001,
            type_4008,
            type_4011,
            type_4013,
            type_4017,
            type_4030,
            type_4040,
            type_4069,
            type_4071,
            type_4081,
            type_4094,
            type_4512,
            type_4514,
            type_4801
        };

        class IComponent
        {
            public:
                virtual ~IComponent() = default;
                
                virtual void simulate(std::size_t tick) = 0;
                virtual nts::Tristate compute(std::size_t pin) = 0;
                virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin) = 0;
                virtual void dump() const = 0;
        };
    };

#endif /* _INTERFACE_HPP_ */