#pragma once

#include <utility>
#include <vector>
#include <string>


class Inventory {
public:
    explicit Inventory();
    virtual ~Inventory();

    void show();
    void add(std::string sItemName);
    void remove(std::string sItemName);

private:
    std::vector<std::string> vItems;
};