#include <iostream>
#include "App.h"
#include "Advert.h"

App::App() : cur_user(User()) {
    std::cout << "App created\n";
}

App::~App() {
    if (chat)
        delete chat;
    if (advert)
        delete advert;

    std::cout << "App exited\n";
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

void App::create_advert() {
    advert = new Advert();
}

void App::set_advert_info(int room_num, std::string address) {
    advert->set_room_num(room_num);
    advert->set_address(address);
}

void App::make_advert_do_smth() {
    advert->do_smth();
}
