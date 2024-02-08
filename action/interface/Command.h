#pragma once

#include "../../other/includes.h"
#include "../../player/Player.h"

class Command {
public:
    virtual void execute() = 0;
    virtual std::string getDescription() const = 0;
};