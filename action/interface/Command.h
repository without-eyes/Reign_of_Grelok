#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <memory>
#include <vector>
#include <string>

#include "../../player/Player.h"

class Command {
public:
    virtual void execute() = 0;

    virtual std::string getDescription() const = 0;
};