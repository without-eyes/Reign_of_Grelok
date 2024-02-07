#pragma once

#include "../interface/Command.h"

class GoEast : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};