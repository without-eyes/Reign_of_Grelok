#pragma once

#include <rog/action/interface/Command.h>

class Back : public Command {
public:
    void execute() override;

    std::string getDescription() const override;

};
