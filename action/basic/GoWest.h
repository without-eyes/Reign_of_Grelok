#pragma once

#include "../interface/Command.h"

class GoWest : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};