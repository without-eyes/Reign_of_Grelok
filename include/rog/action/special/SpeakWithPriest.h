#pragma once

#include <rog/action/interface/Command.h>

class SpeakWithPriest : public Command {
public:
    void execute() override;

    std::string getDescription() const override;
};
