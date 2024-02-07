#pragma once

#include "../interface/Command.h"

class GoSouth : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};