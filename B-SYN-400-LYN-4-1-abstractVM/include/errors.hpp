#ifndef ERRORS_HPP

    #define ERRORS_HPP

    #include <iostream>
    #include <stdexcept>
    #include <array>
    #include <cstring>

    #define FILE_NOT_FOUND "file not found: "
    #define OVERFLOW "overflow on a value: "
    #define UNDERFLOW "underflow on a value: "
    #define SHORT_STACK "the stack must have two value at least: "
    #define EMPTY_STACK "pop instruction on an empty stack: "
    #define EMPTY_REGISTER "load instruction on an empty register: "
    #define SYNTACTICAL "the assembler program has one, or several, syntactical errors: "
    #define DIVISION_ZERO "division by zero: "
    #define EXIT "the program does not have an exit instruction: "
    #define ASSERT "an assert instruction is not verified: "
    #define ARITHMETICAL "the stack strictly has less than two values during the execution of an arithmetical instruction: "

    // LEXICAL
    #define LEXICAL "the assembler program has one, or several, lexical errors: "
    #define COMMAND_NOT_FOUND "invalid command: "
    #define TYPE_NOT_FOUND "type not found: "
    #define PARENTHESE_MISSING "missing parenthesis: "

    // SYNTACTICAL
    #define COMMAND_TYPE_INVALID "command type invalid: "
    #define COMMAND_TYPE_IS_REQUIRED "a command type is required: "
    #define COMMAND_TYPE_IS_NOT_REQUIRED "no command type is required: "
    #define INVALID_TYPE_VALUE "the value entered is not the good type: "
    #define BAD_FORMAT_TYPE_VALUE "bad format for type value: "
    #define WRONG_TYPE_VALUE "wrong type value: "

    // MODULO
    #define MODULO_ZERO "modulo error: modulo by zero: "
    #define MODULO_FLOAT "modulo error: modulo by floating: "

    class Exception : public std::exception
    {
        public:
            Exception(std::string, const std::string &) noexcept;
            virtual ~Exception() override = default;
            virtual const char* what() const noexcept override;

        private:
            std::string _errorCode;
            std::string _message;
    };

#endif /* ERRORS_HPP */

