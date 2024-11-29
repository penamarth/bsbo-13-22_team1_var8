#include <iostream>
#include "App.h"

App::App() : cur_user(User()) {
    std::cout << "App created\n";
}

void App::open_chat() {
    std::cout << "App opened the Chat\n";
    chat = new Chat();
}

void App::send_message() {
    chat->send_message();
}

void App::get_new_messages() {
    chat->get_new_messages();
}
