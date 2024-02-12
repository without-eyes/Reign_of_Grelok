#pragma once

#include "rog/action/interface/Command.h"

class LookAround : public Command {
public:
    enum class LocationType {
        Plains,
        Mountainside,
        Chapel,
        Swamp,
        Town,
    };

    void execute() override;
    std::string getDescription() const override;

private:
    static LocationType getLocationType();
};