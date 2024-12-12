#pragma once
#include "EmptyClasses.h"
#include "Chat.h"
#include "Advert.h"
#include <vector>

class App {
private:
    User cur_user;
    Chat *chat = nullptr;
    Advert *advert = nullptr;
    std::vector<Advert*> adverts;

public:
    App();
    ~App();
    void open_chat();
    void send_message();
    void get_new_messages();

    void create_advert();
    void set_advert_info(int room_num, std::string address);
    void make_advert_do_smth();

    void fetch_adverts();
    void filter_adverts_cheap_first();
    void get_first_found_advert();

    void apply_for_rent();
};
