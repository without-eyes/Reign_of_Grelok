#pragma once

#include "../interface/Command.h"
#include "../../userinterface/textoutput/TextOutput.h"
#include "../../player/Inventory.h"
#include "LocationEvents.h"

class ExamineGrave : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};


