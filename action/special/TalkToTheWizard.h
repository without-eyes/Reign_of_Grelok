#pragma once

#include "../interface/Command.h"
#include "../../player/Inventory.h"

class TalkToTheWizard : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};
