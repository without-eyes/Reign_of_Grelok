#pragma once


#include "rog/player/Player.h"
#include <string>

class Command {
public:
    virtual void execute() = 0;
    virtual std::string getDescription() const = 0;
};