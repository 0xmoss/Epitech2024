/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14A-
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

// --------------------
// NasaError BEGINNNIG
// --------------------

NasaError::NasaError(
    std::string const &message, std::string const &component
) : message(message), component(component)
{
    return;
}

NasaError::NasaError(
    std::string const &message
) : message(message), component("Unknown")
{
    return;
}

NasaError::~NasaError() throw()
{
    return;
}

// --------------------
// NasaError END
// --------------------

// --------------------
// MissionCriticalError BEGINNING
// --------------------

MissionCriticalError::MissionCriticalError(
    std::string const &message, std::string const &component
) : NasaError(message, component)
{
    return;
}

MissionCriticalError::MissionCriticalError(
    std::string const &message
) : NasaError(message)
{
    return;
}

MissionCriticalError::~MissionCriticalError() throw()
{
    return;
}

// --------------------
// MissionCriticalError END
// --------------------

// --------------------
// LifeCriticalError BEGINNING
// --------------------

LifeCriticalError::LifeCriticalError(
    std::string const &message, std::string const &component
) : NasaError(message, component)
{
    return;
}

LifeCriticalError::LifeCriticalError(
    std::string const &message
) : NasaError(message)
{
    return;
}

LifeCriticalError::~LifeCriticalError() throw()
{
    return;
}

// --------------------
// LifeCriticalError END
// --------------------

// --------------------
// UserError BEGINNING
// --------------------

UserError::UserError(
    std::string const &message, std::string const &component
) : NasaError(message, component)
{
    return;
}

UserError::UserError(
    std::string const &message
) : NasaError(message)
{
    return;
}

UserError::~UserError() throw()
{
    return;
}

// --------------------
// UserError END
// --------------------

// --------------------
// CommunicationError BEGINNING
// --------------------

CommunicationError::CommunicationError(
    std::string const &message
) : NasaError(message, "CommunicationDevice")
{
    return;
}

CommunicationError::~CommunicationError() throw()
{
    return;
}

// --------------------
// CommunicationError END
// --------------------

// --------------------
// Handler BEGINNING
// --------------------

std::string NasaError::display() noexcept
{
	return (this->message);
}

std::string const &NasaError::getComponent() const
{
	return (this->component);
}

// --------------------
// Handler END
// --------------------