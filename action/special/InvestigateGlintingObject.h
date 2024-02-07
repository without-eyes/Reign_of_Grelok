#pragma once

#include "../interface/Command.h"
#include "../../userinterface/menu/Menu.h"
#include "LocationEvents.h"

class InvestigateGlintingObject : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};