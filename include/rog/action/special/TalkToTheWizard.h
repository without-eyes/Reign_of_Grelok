#pragma once

#include <rog/action/interface/Command.h>

class TalkToTheWizard : public Command {
public:
    void execute() override;

    std::string getDescription() const override;
};
