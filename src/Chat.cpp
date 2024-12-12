#include "Chat.h"
#include <iostream>

Chat::Chat() {
    std::cout << "Chat created\n";
}

Chat::~Chat() {
    std::cout << "Chat closed\n";
}

void Chat::send_message() {
    std::cout << "Message sent\n";
}

void Chat::get_new_messages() {
    std::cout << "New messages received\n";
}
