#include <iostream>
#include "Advert.h"

Advert::Advert() : state(new InactiveAdvert()) {
    std::cout << "Advert created\n";
}

Advert::~Advert() {
    delete state;
    std::cout << "Advert object cleared\n";
}

void Advert::set_room_num(int room_num) {
    this->room_num = room_num;
    std::cout << "Advert room number set to " << room_num << "\n";
}

void Advert::set_address(std::string address) {
    this->address = address;
    std::cout << "Advert address set to " << address << "\n";
}

void Advert::activate() {
    delete state;
    state = new ActiveAdvert();
}

void Advert::diactivate() {
    delete state;
    state = new InactiveAdvert();
}

void Advert::do_smth() {
    state->do_smth();
}

void ActiveAdvert::do_smth() {
    std::cout << "ActiveAdvert did something\n";
}

void InactiveAdvert::do_smth() {
    std::cout << "InactiveAdvert did something\n";
}
