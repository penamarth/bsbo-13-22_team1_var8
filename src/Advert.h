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

public:
    Advert();
    ~Advert();
    void set_room_num(int room_num);
    void set_address(std::string address);
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
