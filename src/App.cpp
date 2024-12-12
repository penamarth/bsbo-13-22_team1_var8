#include <iostream>
#include <algorithm>
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

void App::fetch_adverts() {
    adverts.push_back(new Advert(3, "Ustal pridumivat, 3", 64000));
    adverts.push_back(new Advert(2, "Net Sil pridumivat, 4", 48000));
    std::cout << "Adverts fetched\n";
}

void App::filter_adverts_cheap_first() {
    std::sort(adverts.begin(), adverts.end(), [](const Advert *a, const Advert *b) {
        return a->get_cost() < b->get_cost();
    });
    std::cout << "Adverts filtered cheap first\n";
}

void App::get_first_found_advert() {
    std::cout << "Getting first found advert\n";
    adverts[0]->print();
}
