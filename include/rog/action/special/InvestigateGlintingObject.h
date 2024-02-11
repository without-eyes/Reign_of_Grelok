#pragma once

#include "rog/action/interface/Command.h"
#include "rog/ui/menu/Menu.h"
#include "LocationEvents.h"

class InvestigateGlintingObject : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};