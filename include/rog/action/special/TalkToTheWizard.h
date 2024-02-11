#pragma once

#include "rog/action/interface/Command.h"
#include "rog/player/Inventory.h"

class TalkToTheWizard : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};
