#pragma once

#include "../interface/Command.h"
#include <conio.h>
#include <iostream>

class LookAround : public Command {
public:
    LookAround(short sX, short sY);

    void execute() override;
    std::string getDescription() const override;

private:
    std::string sLocationName;
};