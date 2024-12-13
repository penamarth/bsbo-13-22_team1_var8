#pragma once
#include "EmptyClasses.h"
#include <string>

class AdvertState {
public:
    virtual ~AdvertState() {}
    virtual void do_smth() = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
};

class Advert {
private:
    AdvertState *state = nullptr;
    int room_num = 0;
    std::string address = "";
    double cost = 0.0;
    User owner;
    User renter;

public:
    Advert();
    Advert(int room_num, std::string address, double cost);
    ~Advert();
    void print();
    double get_cost() const;
    void set_room_num(int room_num);
    void set_address(std::string address);
    void set_cost(double cost);
    void set_renter(User renter);
    void activate();
    void deactivate();
    void do_smth();
};

class ActiveAdvert : public AdvertState {
private:
    AdvertState **state = nullptr;
public:
    ActiveAdvert(AdvertState **state);
    void activate() override;
    void deactivate() override;
    void do_smth() override;
};

class InactiveAdvert : public AdvertState {
private:
    AdvertState **state = nullptr;
public:
    InactiveAdvert(AdvertState **state);
    void activate() override;
    void deactivate() override;
    void do_smth() override;
};
