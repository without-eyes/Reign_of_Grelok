#pragma once

#include "../interface/Command.h"
#include "../../userinterface/textoutput/TextOutput.h"

class LookAround : public Command {
public:
    LookAround(short sX, short sY);

    void execute() override;
    std::string getDescription() const override;

private:
    std::string sLocationName;
};