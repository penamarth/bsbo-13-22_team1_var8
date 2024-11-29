#pragma once
#include "EmptyClasses.h"
#include "Chat.h"

class App {
private:
    User cur_user;
    Chat *chat = nullptr;

public:
    App();
    void open_chat();
    void send_message();
    void get_new_messages();
};
