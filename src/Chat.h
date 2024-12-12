#pragma once
#include <string>
#include <vector>
#include "EmptyClasses.h"

class Chat {
private:
    User one;
    User two;
    std::vector<std::string> messages;

public:
    Chat();
    ~Chat();
    void send_message();
    void get_new_messages();
};
