/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Toy.hpp
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

    #include <iostream>
    #include <string>

    #include "Picture.hpp"

    class Toy {
        public:
            enum ToyType {
                BASIC_TOY,
                ALIEN,
                BUZZ,
                WOODY
            };
            class Error {
                public:
                    enum ErrorType {
                        UNKNOWN,
                        PICTURE,
                        ERROR
                    };
                public:
                    ErrorType type;

                    Error();
                    void setType(ErrorType);
            };
            
            Toy();
            Toy(ToyType, std::string const &, std::string const &);
            Toy(Toy const &);
            virtual ~Toy();

            int getType() const;
            std::string const &getName() const;
            std::string const &getAscii() const;

            void setName(std::string const &);
            bool setAscii(std::string const &);

            virtual void display(std::string const);

            Toy::Error const &getLastError() const;

            Toy &operator = (Toy const &);
            Toy &operator << (std::string const &);

        protected:
            ToyType type;
            std::string name;
            Picture picture;
            Error error;
    };

std::ostream &operator << (std::ostream &, Toy const &);

#endif /* !TOY_HPP_ */