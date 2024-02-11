#pragma once

#include "rog/action/interface/Command.h"
#include "rog/ui/textoutput/TextOutput.h"
#include "rog/action/special/LocationEvents.h"

class LookAround : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};