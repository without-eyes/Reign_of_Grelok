#pragma once

#include "../interface/Command.h"

class GoNorth : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};