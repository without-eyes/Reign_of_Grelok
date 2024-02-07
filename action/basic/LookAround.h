#pragma once

#include "../interface/Command.h"
#include "../../userinterface/textoutput/TextOutput.h"
#include "../special/LocationEvents.h"

class LookAround : public Command {
public:
    LookAround();

    void execute() override;
    std::string getDescription() const override;

private:
    std::string sLocationName;
};