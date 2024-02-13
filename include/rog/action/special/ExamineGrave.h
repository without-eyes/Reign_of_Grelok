#pragma once

#include <rog/action/interface/Command.h>

class ExamineGrave : public Command {
public:
    void execute() override;
    std::string getDescription() const override;
};


