#include <iostream>
#include "Advert.h"

Advert::Advert() : state(new InactiveAdvert()) {
    std::cout << "Advert created\n";
}

Advert::Advert(int room_num, std::string address, double cost) :
    room_num(room_num), address(address), state(new InactiveAdvert()), cost(cost) {}

Advert::~Advert() {
    delete state;
    std::cout << "Advert object cleared\n";
}

void Advert::print() {
    std::cout << "Advert: room_num = " << room_num << "; address = " << address << "; cost = " << cost << "\n";
}

double Advert::get_cost() const {
    return cost;
}

void Advert::set_room_num(int room_num) {
    this->room_num = room_num;
    std::cout << "Advert room number set to " << room_num << "\n";
}

void Advert::set_address(std::string address) {
    this->address = address;
    std::cout << "Advert address set to " << address << "\n";
}

void Advert::set_cost(double cost) {
    this->cost = cost;
    std::cout << "Advert cost set to " << cost << "\n";
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
