#include <iostream>
#include "Advert.h"

Advert::Advert() : state(new InactiveAdvert(&state)) {
    std::cout << "Advert created\n";
}

Advert::Advert(int room_num, std::string address, double cost) :
    room_num(room_num), address(address), state(new InactiveAdvert(&state)), cost(cost) {}

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

void Advert::set_renter(User renter) {
    this->renter = renter;
    std::cout << "Advert renter set\n";
}

void Advert::activate() {
    state->activate();
}

void Advert::deactivate() {
    state->deactivate();
}

void Advert::do_smth() {
    state->do_smth();
}

ActiveAdvert::ActiveAdvert(AdvertState **state) : state(state) {}

void ActiveAdvert::do_smth() {
    std::cout << "ActiveAdvert did something\n";
}

void ActiveAdvert::activate() {
    std::cout << "ActiveAdvert can't be activated\n";
}

void ActiveAdvert::deactivate() {
    std::cout << "ActiveAdvert deactivated\n";
    AdvertState *ad = new InactiveAdvert(state);
    AdvertState *old_state = *state;
    *state = ad;
    delete old_state;
}

InactiveAdvert::InactiveAdvert(AdvertState **state) : state(state) {}

void InactiveAdvert::do_smth() {
    std::cout << "InactiveAdvert did something\n";
}

void InactiveAdvert::activate() {
    std::cout << "InactiveAdvert activated\n";
    AdvertState *ad = new ActiveAdvert(state);
    AdvertState *old_state = *state;
    *state = ad;
    delete old_state;
}
void InactiveAdvert::deactivate() {
    std::cout << "InactiveAdvert can't be deactivated\n";
}
