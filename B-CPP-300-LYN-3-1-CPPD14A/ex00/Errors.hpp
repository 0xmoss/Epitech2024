/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14A-
** File description:
** Errors.hpp
*/


#ifndef _ERRORS_HPP_
    #define _ERRORS_HPP_

    #include <iostream>
    #include <string>

    class NasaError : public std::exception
    {
        private:
            std::string message;
            std::string component;
        public:
            NasaError(std::string const &, std::string const &);
            NasaError(std::string const &);

            virtual ~NasaError() throw();

            std::string const &getComponent() const;

            std::string NasaError::display() noexcept;
    };

    class MissionCriticalError : public NasaError
    {
        public:
            MissionCriticalError(std::string const &, std::string const &);
            MissionCriticalError(std::string const &);

            virtual ~MissionCriticalError() throw();
    };

    class LifeCriticalError : public NasaError
    {
        public:
            LifeCriticalError(std::string const &, std::string const &);
            LifeCriticalError(std::string const &);

            virtual ~LifeCriticalError() throw();
    };

    class UserError : public NasaError
    {
        public:
            UserError(std::string const &, std::string const &);
            UserError(std::string const &);

            virtual ~UserError() throw();
    };

    class CommunicationError : public NasaError
    {
        public:
            CommunicationError(std::string const &);

            virtual ~CommunicationError() throw();
    };

#endif /* !_ERRORS_HPP_ */