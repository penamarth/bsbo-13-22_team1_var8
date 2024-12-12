#pragma once
#include <string>

class AdvertState {
public:
    virtual ~AdvertState() {}
    virtual void do_smth() = 0;
};

class Advert {
private:
    AdvertState *state = nullptr;
    int room_num = 0;
    std::string address = "";
    double cost = 0.0;

public:
    Advert();
    Advert(int room_num, std::string address, double cost);
    ~Advert();
    void print();
    double get_cost() const;
    void set_room_num(int room_num);
    void set_address(std::string address);
    void set_cost(double cost);
    void activate();
    void diactivate();
    void do_smth();
};

class ActiveAdvert : public AdvertState {
public:
    void do_smth() override;
};

class InactiveAdvert : public AdvertState {
public:
    void do_smth() override;
};
