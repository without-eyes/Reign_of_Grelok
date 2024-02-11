#pragma once

#include "rog/action/interface/Command.h"
#include "rog/ui/textoutput/TextOutput.h"
#include "rog/player/Inventory.h"
#include "LocationEvents.h"

class ExamineGrave : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};


