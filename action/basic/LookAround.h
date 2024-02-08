#pragma once

#include "../interface/Command.h"
#include "../../userinterface/textoutput/TextOutput.h"
#include "../special/LocationEvents.h"

class LookAround : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};